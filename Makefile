CC = cc

CFLAGS = -g -Wall -Werror -Wextra

NAME = so_long

SRC = 	./src/main.c \
		./src/validate_map.c \
		./src/game_ctl.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

LIBFT =	./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

LIB = $(LIBFT) $(FT_PRINTF)


all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

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