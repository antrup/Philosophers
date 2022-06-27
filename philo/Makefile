# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atruphem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 16:56:02 by atruphem          #+#    #+#              #
#    Updated: 2021/07/03 19:41:41 by toni             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJ =  clean.o ft_atoi.o init.o life.o philo.o tools.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -pthread -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra -I . -pthread -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
