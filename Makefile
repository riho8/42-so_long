NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = mlx_linux/Makefile.gen
LIBFT = libft/libft.a
LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
SRCS = src/so_long.c \
		src/map.c \
		src/check_map.c \
		src/error_free_exit.c \
		src/image.c \
		src/hook.c \
		src/move.c \

all: $(NAME) $(MLX) $(LIBFT) 

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -g -fsanitize=address -o  $(NAME) $(SRCS) $(LIBFT) $(LIB)

$(LIBFT):
	$(MAKE) -C libft 

clean:
	$(MAKE) clean -C libft
	
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
