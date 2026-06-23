CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
NAME = libftprintf.a
SRC = ft_printf.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_printf_utils.c ft_bzero.c ft_calloc.c ft_itoa.c ft_memset.c ft_putchar_fd.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
