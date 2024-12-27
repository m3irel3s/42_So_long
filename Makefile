NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I. -I$(INC_DIR)

SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = 42_Libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = libs/minilibx-linux

UTILS_DIR = $(SRC_DIR)/utils
INVALID_MAPS_DIR = $(SRC_DIR)/maps/invalid_maps
VALID_MAPS_DIR = $(SRC_DIR)/maps/valid_maps
INVALID_PATHS_DIR = $(SRC_DIR)/maps/invalid_paths
PARSING_DIR = $(SRC_DIR)/parsing
INITS_DIR = $(SRC_DIR)/inits
RENDER_DIR = $(SRC_DIR)/render
HANDLERS_DIR = $(SRC_DIR)/handlers
MOVES_DIR = $(SRC_DIR)/moves
VALID_PATH_CHECKER_DIR = $(SRC_DIR)/valid_path_checker

SRC = $(SRC_DIR)/main.c \
		$(INITS_DIR)/init_structs.c \
		$(PARSING_DIR)/map_name_checker.c \
		$(PARSING_DIR)/map_validation.c \
		$(PARSING_DIR)/map_chars_checker.c \
		$(UTILS_DIR)/error.c \
		$(UTILS_DIR)/free.c \
		$(UTILS_DIR)/map_utils.c \
		$(UTILS_DIR)/player_utils.c \
		$(RENDER_DIR)/render_win.c \
		$(RENDER_DIR)/preload_imgs.c \
		$(RENDER_DIR)/replace_img.c \
		$(HANDLERS_DIR)/handle_key_press.c \
		$(MOVES_DIR)/moves.c \
		$(MOVES_DIR)/moves_conditions.c \
		$(VALID_PATH_CHECKER_DIR)/flood_fill.c \

# VARGS = --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes
VARGS = --track-origins=yes
MLXFLAGS = -L ./$(MLX_DIR) -lm -lmlx -Ilmlx -lXext -lX11

#TEST VALIDS
VALID_MAP = ./$(VALID_MAPS_DIR)/.ber

all: $(LIBFT) $(NAME) $(MINILIBX)

$(LIBFT_DIR):
	git clone git@github.com:m3irel3s/42_Libft.git $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLXFLAGS)

$(MINILIBX):
	$(MAKE) -C ./libs/minilibx-linux

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

val: $(NAME) $(SRC)
	valgrind $(VARGS) ./$(NAME) $(VALID_MAPS_DIR)/long_map.ber

test_valid_1: $(NAME)
	./$(NAME) $(VALID_MAPS_DIR)/map.ber

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re