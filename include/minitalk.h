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
# include <limits.h>
#include <stdio.h>
#include <string.h>
# include "../libft/libft.h"

#define MAX_WIDTH 80
#define BORDER_CHAR '-'

typedef struct s_list_client
{
    pid_t   pid[32768];
}           t_list_client;

void	sigusr_handler(int sig, siginfo_t *info, void *context);
void	error_exit(int server_pid);
void	send_sms(pid_t pid, char *sms);

int     check_is_number(char *num_in_char);

char     *format_message(const char *name, const char *sms);

#endif
