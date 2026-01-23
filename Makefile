CC = cc
CFLAGS = -Wall -Werror -Wextra -Imlx -Iinc -Ilib/libft -Ilib/gnl -Ilib/ft_printf

NAME = so_long

SRC = 	./src/main.c \
		./src/game/game_ctl.c \
		./src/game/start_game.c \
		./src/game/moves.c \
		./src/game/event_handle.c \
		./src/game/utils.c \
		./src/map/validate_map.c \
		./src/map/path_checks.c \
		./src/map/structure_checks.c \
		./src/map/get_map.c \
		./lib/gnl/get_next_line.c \
		./lib/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = ./lib/libft/libft.a
FT_PRINTF = ./lib/ft_printf/libftprintf.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIB = $(LIBFT) $(FT_PRINTF) $(MLX_LIB)

all: $(NAME)

$(NAME):  $(MLX_DIR) $(OBJ) $(LIB)
	@echo "Building game..."
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIB) -o $@
	@echo "Done! To play: ./so_long <path_to_map>"

%.o: %.c
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C lib/libft

$(FT_PRINTF):
	@$(MAKE) -C lib/ft_printf

$(MLX_LIB): $(MLX_DIR)
	@echo "Compiling MLX..."
	@$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	@echo "MinilibX not found, cloning..."
	@git clone https://github.com/42Paris/minilibx-linux.git mlx
	@echo "MinilibX cloned into $(MLX_DIR)"

clean:
	@$(MAKE) -C lib/libft clean
	@$(MAKE) -C lib/ft_printf clean
	@$(MAKE) -C mlx
	@echo "Removed object files."
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C lib/libft fclean
	@$(MAKE) -C lib/ft_printf fclean
	@rm -f $(NAME)
	@echo "Removed executable."

re: fclean all

.PHONY: all clean fclean re
