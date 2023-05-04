CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_convert_base.c \
		ft_print_char.c \
		ft_print_hex.c \
		ft_print_int.c \
		ft_print_point.c \
		ft_print_string.c \
		ft_print_uint.c \
		ft_printf.c \
		ft_putchar_fd_2.c \
		ft_putstr_fd_2.c \
		ft_putnbr_fd_2.c \
		ft_strlen.c
OBJS = $(SRCS:.c=.o) 

all : $(NAME)

$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) 

fclean:clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re