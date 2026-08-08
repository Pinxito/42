# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/08 05:13:23 by gguillen          #+#    #+#              #
#    Updated: 2026/08/08 05:13:29 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.cpp src/Zombie.cpp src/zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Horde

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re