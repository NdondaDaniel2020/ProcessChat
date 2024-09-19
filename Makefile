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

INCLUDE = ./include/
SERVER = server
CLIENTE = client
LIBFT = ./libft/libft.a

all: $(CLIENTE)

$(LIBFT):
	$(MAKE) bonus -C ./libft/

$(CLIENTE):	$(LIBFT)
	$(CC) $(CFLAGS) ./src/$(CLIENTE).c $(LIBFT) -I$(INCLUDE) -o $(CLIENTE)
	$(CC) $(CFLAGS) ./src/$(SERVER).c  $(LIBFT) -I$(INCLUDE) -o $(SERVER)

m: $(CLIENTE)
	# make clean

n:
	norminette .

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENTE)
	$(MAKE) fclean -C ./libft/

re: fclean all

r: eclean m
	clear

.PHONY: all clean fclean re
