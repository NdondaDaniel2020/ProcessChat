/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:32:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 13:10:33 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_received = 0;

void	signal_received(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Recebido\n");
		exit(1);
	}
	if (signal == SIGUSR1)
		g_received = 1;
}

void	send_sms(pid_t pid, char *sms)
{
	char	bits;
	int		n;
	int		ok;

	ok = 1;
	while (*sms || ok == 1)
	{
		n = 8;
		while (n--)
		{
			g_received = 0;
			bits = ((*sms >> n) & 1);
			if (bits == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_received == 0)
				usleep(100);
		}
		if (*sms == '\0')
			break ;
		++sms;
	}
}

static int	check_is_number(char *num_in_char)
{
	int	i;

	i = 0;
	while (num_in_char[i])
	{
		if (!ft_isdigit(num_in_char[i]))
		{
			if ((num_in_char[i] == '-' || num_in_char[i] == '+')
				&& (i == 0 || num_in_char[i - 1] == ' ')
				&& ft_isdigit(num_in_char[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		value;
	struct sigaction	sa;

	ft_printf("%i\n\n", check_is_number(av[1]));
	if (ac == 3 && check_is_number(av[1]))
	{
		value = ft_atoi(av[1]);
		sa.sa_handler = signal_received;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_sms(value, ft_strjoin(av[2], "\n"));
		while (1)
			pause();
	}
	else
		ft_printf("FALHA NOS ARGUMENTOD PASSADOS\n");
	return (0);
}
