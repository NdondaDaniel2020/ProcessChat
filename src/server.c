/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 10:21:12 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

volatile t_list_client g_list;

char	*ft_charjoin(char *s1, char c, int l2)
{
	char	*join;
	int		l1;
	int		i;

	if (!s1 && !c)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = c;
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_charjoin_free(char *s1, char c, int l2)
{
	char	*join;
	int		l1;
	int		i;

	if (!s1 && !c)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = c;
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

void	init_list_client(void)
{
	int	i;

	i = 0;
	while (i < 32768)
	{
		g_list.pid[i] = 0;
		g_list.client[i] = 0;
		i++;
	}
}

void	add_client_in_list(pid_t pid, char *name)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (i < 32768)
	{
		if (g_list.pid[i] == pid)
			return ;
		i++;
	}
	i = 0;
	while (i < 32768)
	{
		if (g_list.pid[i] == 0)
			pos = i;
		i++;
	}
	if (pos == -1)
		return ;

	pid[pos] = pid;
    *client[pos] = ft_strdup(name);
	name = NULL;
}

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
    static int  i = 0;
    static char cha = 0;
	static char *inf = NULL;

    (void)ucontext;
    cha <<= 1;
    cha |= (sig == SIGUSR2);
    i++;
    if (i == 8)
    {
        printf("%c", cha);
		if (!inf)
			ft_charjoin(inf, cha, 1);
		else
			ft_charjoin_free(inf, cha, 1);
	
        if (cha == '\0')
        {
			add_client_in_list(info->si_pid, inf);
            kill(info->si_pid, SIGUSR2);
        }
        i = 0;
        cha = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa_usr;

    printf("Server PID: %i\n", getpid());
	init_list_client();
    sa_usr.sa_sigaction = sigusr_handler;
    sa_usr.sa_flags = SA_SIGINFO;
    sigemptyset(&sa_usr.sa_mask);
    sigaction(SIGUSR1, &sa_usr, NULL);
    sigaction(SIGUSR2, &sa_usr, NULL);
    while (1)
        pause();
    return (0);
}

