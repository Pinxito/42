# Nombre del programa final
NAME = fractol

# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Rutas de los archivos fuente
SRCS = main.c \
       mandelbrot.c \
       utils.c \
	   utils1.c \
	   julia.c \
	   extras.c \
	   ft_printf.c \
       ft_printf_outils.c \
       ft_printf_outils1.c \
       ft_printf_outils2.c \
       ft_printf_outils3.c \

# Archivos objeto generados a partir de los .c
OBJS = $(SRCS:.c=.o)

# Ruta de MiniLibX
LIBMLX_PATH = /home/papprikka/fract-ol/lib/minilibx
MLX_FLAGS = -L$(LIBMLX_PATH) -lmlx -L/usr/include/X11 -lXext -lX11 -lm -lbsd
INCLUDES = -I$(LIBMLX_PATH)

# Objetivo por defecto
all: $(NAME)

# Regla para compilar los archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Compilación del programa
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

# Eliminar los archivos objeto
clean:
	rm -f $(OBJS)

# Eliminar los archivos objeto y el ejecutable
fclean: clean
	rm -f $(NAME)

# Volver a compilar todo
re: fclean all

# Indica que los siguientes objetivos no son archivos reales
.PHONY: all clean fclean re
