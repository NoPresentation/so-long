CC = cc

CFLAGS = -g -Wall -Werror -Wextra -Imlx -I/usr/include -Iinc -Ilib/libft -Ilib/gnl -Ilib/ft_printf -O3

NAME = so_long

SRC = 	./src/main.c \
		./src/game/game_ctl.c \
		./src/game/start_game.c \
		./src/game/moves.c \
		./src/game/event_handle.c \
		./src/map/validate_map.c \
		./src/map/path_checks.c \
		./src/map/tiles_checks.c \
		./src/map/get_map.c \
		./lib/gnl/get_next_line.c \
		./lib/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

LIBFT =	./lib/libft/libft.a

FT_PRINTF = ./lib/ft_printf/libftprintf.a

MLX_LIB = mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lz

LIB = $(LIBFT) $(FT_PRINTF) $(MLX_LIB)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "Building game..."
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIB) -o $@
	@echo "Done, to play: ./so_long <path_to_map>"

%.o: %.c
	@echo "Compiling src code..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C lib/libft

$(FT_PRINTF):
	@$(MAKE) -C lib/ft_printf

$(MLX_LIB):
	@echo "Compiling MLX..."
	@$(MAKE) -C mlx

clean:
	@echo "Removed object files."
	@$(MAKE) -C lib/libft clean
	@$(MAKE) -C lib/ft_printf clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Removed Excutable."
	@$(MAKE) -C lib/libft fclean
	@$(MAKE) -C lib/ft_printf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re