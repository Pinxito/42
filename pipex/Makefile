NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= pipex.c \
			  pipex_utils.c \
			  ft_split.c \
			  string_utils.c

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
