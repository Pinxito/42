# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/12 20:40:16 by gguillen          #+#    #+#              #
#    Updated: 2026/08/18 06:45:25 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.cpp src/Fixed.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixed
INCLUDE = includes
HEADERS = $(wildcard $(INCLUDE)/*.hpp)
 
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