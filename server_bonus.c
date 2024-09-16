/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 13:06:35 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigusr_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 0;
	static char	cha = 0;

	(void)ucontext;
	cha <<= 1;
	cha |= (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		ft_printf("%c", cha);
		if (cha == '\0')
			kill(info->si_pid, SIGUSR2);
		i = 0;
		cha = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_usr;

	ft_printf(" connect %s\n", list->client[0]);
	ft_printf("PID: %d\n", getpid());
	sa_usr.sa_sigaction = sigusr_handler;
	sa_usr.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_usr.sa_mask);
	sigaction(SIGUSR1, &sa_usr, (void *)&list);
	sigaction(SIGUSR2, &sa_usr, (void *)&list);
	while (1)
		pause();
	return (0);
}
