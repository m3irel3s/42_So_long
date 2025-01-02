NAME        = so_long
NAME_BONUS  = so_long_bonus
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I. -I$(INC_DIR)

MLXFLAGS    = -L ./$(MLX_DIR) -lm -lmlx -Ilmlx -lXext -lX11
VARGS = --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes

SRC_DIR     = src
SRC_BONUS_DIR = src_bonus
INC_DIR     = inc
LIBFT_DIR   = 42_Libft
LIBFT       = $(LIBFT_DIR)/libft.a
MLX_DIR     = libs/minilibx-linux

UTILS_DIR   = $(SRC_DIR)/utils
PARSING_DIR = $(SRC_DIR)/parsing
INITS_DIR   = $(SRC_DIR)/inits
RENDER_DIR  = $(SRC_DIR)/render
HANDLERS_DIR= $(SRC_DIR)/handlers
MOVES_DIR   = $(SRC_DIR)/moves
VALID_PATH_CHECKER_DIR = $(SRC_DIR)/valid_path_checker

UTILS_DIR_BONUS   = $(SRC_BONUS_DIR)/utils
PARSING_DIR_BONUS = $(SRC_BONUS_DIR)/parsing
INITS_DIR_BONUS   = $(SRC_BONUS_DIR)/inits
RENDER_DIR_BONUS  = $(SRC_BONUS_DIR)/render
HANDLERS_DIR_BONUS = $(SRC_BONUS_DIR)/handlers
MOVES_DIR_BONUS   = $(SRC_BONUS_DIR)/moves
VALID_PATH_CHECKER_DIR_BONUS = $(SRC_BONUS_DIR)/valid_path_checker

SRC		=	$(SRC_DIR)/main.c \
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

SRC_BONUS	=	$(SRC_BONUS_DIR)/main.c \
			$(INITS_DIR_BONUS)/init_structs.c \
			$(PARSING_DIR_BONUS)/map_name_checker.c \
			$(PARSING_DIR_BONUS)/map_validation.c \
			$(PARSING_DIR_BONUS)/map_chars_checker.c \
			$(UTILS_DIR_BONUS)/error.c \
			$(UTILS_DIR_BONUS)/free.c \
			$(UTILS_DIR_BONUS)/map_utils.c \
			$(UTILS_DIR_BONUS)/player_utils.c \
			$(RENDER_DIR_BONUS)/render_moves.c \
			$(RENDER_DIR_BONUS)/render_win.c \
			$(RENDER_DIR_BONUS)/preload_imgs.c \
			$(RENDER_DIR_BONUS)/replace_img.c \
			$(HANDLERS_DIR_BONUS)/handle_key_press.c \
			$(MOVES_DIR_BONUS)/moves.c \
			$(MOVES_DIR_BONUS)/moves_conditions.c \
			$(VALID_PATH_CHECKER_DIR_BONUS)/flood_fill.c \



all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLXFLAGS)

$(NAME_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(SRC_BONUS) $(LIBFT) $(MLXFLAGS)

$(LIBFT_DIR):
	git clone git@github.com:m3irel3s/42_Libft.git $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C ./libs/minilibx-linux


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

VALID_MAP = ./src/maps/valid_maps/map1.ber
VALID_MAP_BONUS = ./src_bonus/maps/valid_maps/map1.ber

val: $(NAME) $(SRC)
	valgrind $(VARGS) ./$(NAME) $(VALID_MAP)

val_bonus:  $(NAME_BONUS) $(SRC_BONUS)
	valgrind $(VARGS) ./$(NAME_BONUS) $(VALID_MAP_BONUS)

clean:
	rm -f $(NAME) $(NAME_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
