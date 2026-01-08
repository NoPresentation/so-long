CC = cc

CFLAGS = -g -Wall -Werror -Wextra 

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
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

LIBFT =	./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

MLX = -L./mlx -lmlx -lXext -lX11 -lm -lz

LIB = $(LIBFT) $(FT_PRINTF) $(MLX)


all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(MLX):
	$(MAKE) -C mlx CC="gcc -std=gnu99 -Wno-implicit-function-declaration"

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re