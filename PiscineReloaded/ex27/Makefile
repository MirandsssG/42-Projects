CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SRC = srcs
DIR = includes
SRC_FILES = display_file.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(SRC)/, $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(FLAGS) -I $(DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all