
NAME = nimishell
SRCS = src/main.c src/lexer.c src/parser.c src/exec.c src/builtins.c src/env.c src/utils.c
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I include -I $(LIBFT_DIR)/include

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean c:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean f: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all