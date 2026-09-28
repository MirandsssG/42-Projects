CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_NAME = client
SERVER_NAME = server
LIBFTPRINTF_DIR = includes/libftprintf
LIBFT_DIR = includes/libft
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFTPRINTF) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_SRCS) $(LIBFTPRINTF) $(LIBFT)

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFTPRINTF) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_SRCS) $(LIBFTPRINTF) $(LIBFT)

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR) -f Makefile

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) -f Makefile

clean:
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
