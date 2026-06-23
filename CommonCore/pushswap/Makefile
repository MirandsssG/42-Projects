CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/ -g
AR = ar rc
NAME = push_swap
MAIN = pushswap.c
OPERATION_DIR = operations/push.c \
					operations/rev_rotate.c \
					operations/rotate.c \
					operations/swap.c \
					push_swap.c
HELPERS_DIR = helpers/errors.c \
					helpers/helpers.c \
					helpers/initialize_nodes_a.c \
					helpers/initialize_nodes_b.c \
					helpers/initialize_stack_a.c \
					helpers/sort_stacks.c \
					helpers/sort_three.c \
					helpers/stack_sorted.c \
					helpers/split.c
SRCS = $(OPERATION_DIR) $(HELPERS_DIR)
OBJ = $(SRCS:.c=.o)
LIBFTPRINTF = includes/libftprintf/libftprintf.a
LIBFT = includes/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPRINTF) $(LIBFT) -o $(NAME)

$(LIBFTPRINTF):
	make -C includes/libftprintf/ -f makefile

$(LIBFT):
	make -C includes/libft/ -f makefile

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

comp: all
	$(CC) $(CFLAGS) $(MAIN) $(NAME)
	@./a.out

.PHONY: all clean fclean re comp

