# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/07 22:33:57 by gguillen          #+#    #+#              #
#    Updated: 2026/08/07 23:17:29 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/PhoneBook.cpp src/Contact.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phoneBook
 
all: $(NAME)
 
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
 
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
 
clean:
	$(RM) $(OBJ)
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all
 
.PHONY: all clean fclean re 