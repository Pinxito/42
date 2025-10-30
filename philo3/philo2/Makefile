# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 12:34:02 by gguillen          #+#    #+#              #
#    Updated: 2025/10/29 13:38:11 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo

CC      =   cc

CFLAGS  =   -Wall -Wextra -Werror -g3

SRC     =  main.c \
           parsing.c \
           monitorhelp.c \
           utils.c \
           simulation.c \
           actions.c

OBJ     =   $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
