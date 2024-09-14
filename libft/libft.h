/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:57:43 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/09 15:49:52 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);

int		ft_atoi(const char *nptr);
int		ft_atoi_base(unsigned char *str, int str_base);

char	*ft_strjoin(char const *s1, char const *s2);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*printf*/
int		ft_putnbr_base(long int nb, int base, int tan, int count);
int		ft_put_end_mem(unsigned long long nb, int count);
int		ft_put_unsigned(unsigned int nb, int count);
int		ft_printf(const char *format, ...);
int		ft_nblen(long long nb, int base);
int		ft_putchar(char c, int count);
int		ft_putstr(char *s, int count);

#endif
