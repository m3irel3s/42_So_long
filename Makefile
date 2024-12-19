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
PARSING_DIR = $(SRC_DIR)/parsing
INITS_DIR = $(SRC_DIR)/inits
RENDER_DIR = $(SRC_DIR)/render

SRC = $(SRC_DIR)/main.c \
		$(INITS_DIR)/init_structs.c \
		$(PARSING_DIR)/map_name_checker.c \
		$(PARSING_DIR)/map_validation.c \
		$(PARSING_DIR)/map_chars_checker.c \
		$(UTILS_DIR)/error.c \
		$(UTILS_DIR)/free.c \
		$(UTILS_DIR)/map_utils.c \
		$(RENDER_DIR)/render_win.c \

VARGS = --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes
MLXFLAGS = -L ./$(MLX_DIR) -lm -lmlx -Ilmlx -lXext -lX11

#TEST INVALIDS
TEST_EMPTY = ./$(INVALID_MAPS_DIR)/empty.ber
TEST_CHARS = ./$(INVALID_MAPS_DIR)/invalid_chars.ber
TEST_PATH = ./$(INVALID_MAPS_DIR)/invalid_path.ber
TEST_WALL = ./$(INVALID_MAPS_DIR)/missing_wall.ber
TEST_EXIT = ./$(INVALID_MAPS_DIR)/multiple_exits.ber
TEST_START = ./$(INVALID_MAPS_DIR)/multiple_starts.ber
TEST_COLLECT = ./$(INVALID_MAPS_DIR)/no_collects.ber
TEST_NO_EXIT = ./$(INVALID_MAPS_DIR)/no_exit.ber
TEST_NO_START = ./$(INVALID_MAPS_DIR)/no_start.ber
TEST_NO_RECT = ./$(INVALID_MAPS_DIR)/non_rect.ber
TEST_SMALL = ./$(INVALID_MAPS_DIR)/too_small.ber


#TEST VALIDS
VALID_MAP = ./$(VALID_MAPS_DIR)/long_map.ber


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
	valgrind $(VARGS) ./$(NAME) $(VALID_MAP)

#TESTS FOR INVALID MAPS
test_empty: $(NAME)
	./$(NAME) $(TEST_EMPTY)

test_chars: $(NAME)
	./$(NAME) $(TEST_CHARS)

test_path: $(NAME)
	./$(NAME) $(TEST_PATH)

test_wall: $(NAME)
	./$(NAME) $(TEST_WALL)

test_exit: $(NAME)
	./$(NAME) $(TEST_EXIT)

test_start: $(NAME)
	./$(NAME) $(TEST_START)

test_collect: $(NAME)
	./$(NAME) $(TEST_COLLECT)

test_no_exit: $(NAME)
	./$(NAME) $(TEST_NO_EXIT)

test_no_start: $(NAME)
	./$(NAME) $(TEST_NO_START)

test_no_rect: $(NAME)
	./$(NAME) $(TEST_NO_RECT)

test_small: $(NAME)
	./$(NAME) $(TEST_SMALL)

#TEST VALID MAPS

test_valid_1: $(NAME)
	./$(NAME) $(VALID_MAP)

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re