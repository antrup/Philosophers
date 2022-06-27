# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atruphem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 16:56:02 by atruphem          #+#    #+#              #
#    Updated: 2021/07/05 19:59:48 by atruphem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

OBJ =  clean.o ft_atoi.o ft_itoa.o init.o life.o philo_b.o tools.o ps.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -pthread -o $@

%.o: %.c
	gcc -Wall -Werror -Wextra -g -I . -pthread -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
