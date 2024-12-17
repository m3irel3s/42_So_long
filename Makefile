NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I. -I$(INC_DIR)

SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = 42_Libft
LIBFT = $(LIBFT_DIR)/libft.a
UTILS_DIR = $(SRC_DIR)/utils
MAPS_DIR = $(SRC_DIR)/maps
PARSING_DIR = $(SRC_DIR)/parsing

SRC = $(SRC_DIR)/main.c \
		$(PARSING_DIR)/map_name_checker.c \
		$(UTILS_DIR)/error.c \
		$(UTILS_DIR)/free.c \
		$(UTILS_DIR)/init_structs.c \

all: $(LIBFT) $(NAME)

$(LIBFT_DIR):
	git clone git@github.com:m3irel3s/42_Libft.git $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)

clean:
	rm -f $(NAME)

gdb: all $(NAME)
	tmux split-window -h "gdb --tui --args --log-file=gdb.txt ./$(NAME)"
	tmux resize-pane -L 5
	make get_log

get_log:
	rm -f gdb.txt
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re