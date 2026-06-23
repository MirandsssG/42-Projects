CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
LIB = so_long.a
SRC_DIRS = floodfill parsing
SRCS = main.c exit.c \
	includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c \
	$(addprefix floodfill/, floodfill.c copy_map.c find_player.c is_reachable.c path_valid.c) \
	$(addprefix parsing/, parsing1.c parsing2.c parsing3.c) \
	$(addprefix initialize/, initialize.c) \
	$(addprefix mlx/, initialize_mlx.c load_images.c draw_map.c free_map.c key_handler.c) \
	$(addprefix move/, move_up.c move_left.c move_right.c move_down.c move.c)
OBJ_DIR = objects
OBJ = $(SRCS:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))
LIBFT_DIR = includes/libft
LIBFTPRINTF_DIR = includes/libftprintf
MLIBX_DIR = includes/minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
MLIBX = $(MLIBX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFTPRINTF_DIR)
	@cd $(MLIBX_DIR) && ./configure && $(MAKE)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(LIBFTPRINTF) $(MLIBX) -lXext -lX11 -lm

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objects/$(OBJ)
	rm -rf $(OBJ_DIR)
	@make clean -C ./$(LIBFT_DIR)
	@make clean -C ./$(LIBFTPRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C ./$(LIBFT_DIR)
	@make fclean -C ./$(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
