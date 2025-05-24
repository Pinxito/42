# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: papprikka <papprikka@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 17:05:25 by gguillen          #+#    #+#              #
#    Updated: 2025/05/23 22:45:35 by papprikka        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol


CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS = main.c \
       utils.c \
	   utils1.c \
	   extras.c \
	   ft_printf.c \
       ft_printf_outils.c \
       ft_printf_outils1.c \
       ft_printf_outils2.c \
       ft_printf_outils3.c \
	   tab.c \
	   ft_atof.c \


OBJS = $(SRCS:.c=.o)


LIBMLX_PATH = /home/papprikka/fract-ol/lib/minilibx
MLX_FLAGS = -L$(LIBMLX_PATH) -lmlx -L/usr/include/X11 -lXext -lX11 -lm -lbsd
INCLUDES = -I$(LIBMLX_PATH)


all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)


clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re
