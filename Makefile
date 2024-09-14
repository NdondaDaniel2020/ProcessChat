# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 01:32:20 by nmatondo          #+#    #+#              #
#    Updated: 2024/07/10 16:17:10 by nmatondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
 CLIENTE = client
HEDER = minitalk

SRCS = ./libft/*.c
OBJS = *.o
MINITALK = minitalk.a


all: $(MINITALK)

$(MINITALK):
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(MINITALK) $(OBJS)

bonus:	all

m: $(MINITALK)
	$(CC) $(CFLAGS) $(CLIENTE).c $(HEDER).h $(MINITALK) -o $(CLIENTE)
	$(CC) $(CFLAGS) $(SERVER).c $(HEDER).h $(MINITALK) -o $(SERVER)
	make clean

b: $(MINITALK)
	$(CC) $(CFLAGS) $(CLIENTE)_bonus.c $(HEDER)_bonus.h $(MINITALK) -o $(CLIENTE)
	$(CC) $(CFLAGS) $(SERVER)_bonus.c $(HEDER)_bonus.h $(MINITALK) -o $(SERVER)
	make clean

n:
	norminette .

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER)

eclean: fclean
	rm -f $(MINITALK)
	rm -f $(CLIENTE)

re: fclean all

r: eclean m
	clear

.PHONY: all clean fclean re
