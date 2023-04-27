NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = mlx_linux/libmlx.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIB = -L ./libft -lft -L ./ft_printf -lftprintf -L ./mlx -lXext -lX11 -lmlx -lm -lbsd
SRCS = src/so_long.c \
		src/map.c \
		src/check_map.c \
		src/error_free_exit.c \
		src/image.c \
		src/hook.c \
		src/move.c \

all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) -g -fsanitize=address -o  $(NAME) $(SRCS) $(LIBFT) $(PRINTF) $(MLX) $(LIB)

$(LIBFT):
	$(MAKE) -C libft 

$(MLX):
	$(MAKE) -C mlx_linux

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) clean -C libft 
	$(MAKE) clean -C mlx_linux
	$(MAKE) clean -C ft_printf
	
fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
