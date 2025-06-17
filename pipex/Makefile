# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 01:06:15 by gguillen          #+#    #+#              #
#    Updated: 2025/06/17 20:47:25 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= pipex.c \
			  pipex_utils.c \
			  ft_split.c \
			  string_utils.c \
			  string_utils2.c \
			  pipex_path.c \
			  ft_split_quotes.c \
			  ft_split_quotes_utils.c \
			   ft_split_quotes2.c 

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
