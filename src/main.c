# include "so_long.h"

int main(int argc, char **argv)
{
    int     fd;
	t_game	*game;

    if (argc != 2)
        return (-1);
    fd = open(argv[1], O_RDONLY);
	game = create_game(get_map(fd));
    if (!game || !validate_map(game))
    {
        ft_putstr_fd("Error in\n", 2);
		close_game(game);
		return (-1);
    }
	int i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	ft_printf("OK\n");
	start_game(game);
    return (0);
}
