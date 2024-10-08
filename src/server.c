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

void	init_list_client(void)
{
	int	i;

	i = 0;
	while (i < 32768)
	{
		g_list.pid[i] = 0;
		i++;
	}
}

void	list_client(void)
{
	int	i;

	i = 0;
	while (i < 32768)
	{
		if (g_list.pid[i] != 0)
			ft_printf("[%i]\n", g_list.pid[i]);
		i++;
	}
}

void	add_client_in_list(pid_t pid)
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
	g_list.pid[pos] = pid;
}

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
    static int  i = 0;
    static char cha = 0;

    (void)ucontext;
    cha <<= 1;
    cha |= (sig == SIGUSR2);
    i++;
    if (i == 8)
    {
        printf("%c", cha);
	
        if (cha == '\0')
        {
			list_client();
			add_client_in_list(info->si_pid);
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
