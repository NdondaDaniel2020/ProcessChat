/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:32:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 12:30:52 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received = 0;

void	signal_received(int signal)
{
	if (signal == SIGUSR2)
	{
		g_received = 1;
		ft_printf("\n");
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

int	check_is_number(char *num_in_char)
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
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	error_exit(int server_pid)
{
	if (kill(server_pid, 0) != 0)
	{
		ft_putstr_fd("\n", 1);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int		value;
	char	*str;
	struct sigaction	sa;

	if (ac == 3 && check_is_number(av[1]))
	{
		value = ft_atoi(av[1]);
		str = ft_strjoin(av[2], "\n");
		sa.sa_handler = signal_received;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		error_exit(value);
		send_sms(value, str);
		while (1)
		{
			str = get_next_line(0);
			if (str[0] == '\0' || str[0] == '\n')
			{
				free(str);
				exit(1);
			}
			else
				send_sms(value, str);
			free(str);
		}
	}
	else
		ft_printf("ERROR\n");
	return (0);
}