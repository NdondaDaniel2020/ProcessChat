/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:24:33 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/10 15:36:00 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limts.h>
# include "./libft/libft.h"

typedef struct s_list_client
{
    char    *client[INT_MAX];
}           t_list_client;

void	sigusr_handler(int sig, siginfo_t *info, void *context);
void	error_exit(int server_pid);
void	send_sms(pid_t pid, char *sms);

int     check_is_number(char *num_in_char);

#endif
