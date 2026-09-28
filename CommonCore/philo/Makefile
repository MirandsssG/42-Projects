CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -Iincludes/ -g
AR = ar rc
NAME = philo
SRCS = main.c \
		$(addprefix helpers/, ft_atoi.c is_valid_arg.c get_time_ms.c ft_usleep.c) \
		$(addprefix initialization/, init_data.c) \
		$(addprefix cleanup/, cleanup_data.c) \
		$(addprefix parsing/, parsing.c) \
		$(addprefix execute/, execute.c philo_routine.c start_philo.c monitor_routine.c handle_one.c) \
		$(addprefix actions/, eat.c put_forks.c sleep_and_think.c take_forks.c print_status.c) 
OBJ_DIR = objects
OBJ = $(SRCS:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re comp