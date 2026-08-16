# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/07 22:15:59 by gguillen          #+#    #+#              #
#    Updated: 2026/08/08 03:05:24 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= src/main.cpp src/Fixed.cpp
OBJ			= $(SRC:.cpp=.o)
CC			= c++
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= fixed
INCLUDE		= includes
HEADERS		= $(wildcard $(INCLUDE)/*.hpp)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re