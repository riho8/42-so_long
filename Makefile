NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	MLX = mlx_linux/libmlx.a
	LIB = -L ./libft -lft -L ./ft_printf -lftprintf -L ./mlx_linux -lXext -lX11 -lmlx
else
	MLX = mlx_linux/libmlx_Darwin.a
	LIB = -L ./libft -lft -L ./ft_printf -lftprintf -framework OpenGL -framework AppKit -L ./mlx_linux -lmlx   -I/opt/X11/include -L/usr/X11R6/lib  -lX11 -lXext
endif

SRCS = src/so_long.c \
		src/read_file.c \
		src/init_map.c \
		src/check_map.c \
		src/check_map_utils.c \
		src/error_free_exit.c \
		src/image.c \
		src/hook.c \
		src/move.c \

all: $(NAME) $(MLX) $(LIBFT) $(PRINTF)

$(NAME): $(SRCS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) -o  $(NAME) $(SRCS) $(LIBFT) $(PRINTF) $(MLX) $(LIB)

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
