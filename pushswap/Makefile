# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 15:46:45 by gguillen          #+#    #+#              #
#    Updated: 2025/06/01 12:42:38 by gguillen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

DIR_SRC = ./
DIR_UTILS = ./

SRC_FILES = main.c \
            input.c \
            pushutils.c \
            reverseutils.c \
            rotateutils.c \
            stack_utils.c \
            swaputils.c \
            sort.c \
            sorting_chunk.c \
            sorting_radix.c \
			sorting_chunk_utils.c \
			sorting_chunk1.c \
			ft_atoi.c \

UTILS_FILES = ft_split.c \
			  ft_free.c \
              ft_printf.c \
              ft_printf_outils.c \
              ft_printf_outils1.c \
              ft_printf_outils2.c \
              ft_printf_outils3.c \
              ft_printf_stack.c 

# Generar la lista de archivos fuente completos
SRC = $(addprefix $(DIR_SRC), $(SRC_FILES)) \
      $(addprefix $(DIR_UTILS), $(UTILS_FILES))

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Regla principal
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compilación de archivos .c a .o
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	rm -f $(OBJ)

# Limpieza total (objetos + ejecutable)
fclean: clean
	rm -f $(NAME)

# Recompilación desde cero
re: fclean all

# Comandos personalizados
norme:
	@clear
	@if ! norminette | grep "Error"; then echo "\033[32mOK!\033[0m"; fi

propre:
	@make all -s
	@make clean -s

test:
	@clear
	@make propre -s
	@echo "Resultado del programa ./push_swap:"
	@echo
	@./push_swap

val:
	@clear
	@make propre -s
	@echo "Ejecutando Valgrind en ./push_swap:"
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap

.PHONY: all clean fclean re norme propre test val
