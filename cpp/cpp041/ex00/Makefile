# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/19 16:19:12 by gguillen          #+#    #+#              #
#    Updated: 2026/08/19 17:12:49 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= animal

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD -MP

RM			= rm -rf

SRCS		= src/main.cpp \
			  src/Animal.cpp \
			  src/Cat.cpp \
			  src/Dog.cpp \
			  src/WrongAnimal.cpp \
			  src/WrongCat.cpp

OBJS_DIR	= build/

OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re