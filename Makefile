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

MLX = -L./mlx -lmlx -lXext -lX11 -lm -lz

LIB = $(LIBFT) $(FT_PRINTF) $(MLX)


all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C lib/libft

$(FT_PRINTF):
	$(MAKE) -C lib/ft_printf

$(MLX):
	$(MAKE) -C mlx

clean:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re