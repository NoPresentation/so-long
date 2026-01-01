# include "so_long.h"

int main(int argc, char **argv)
{
    int     fd;
	t_game	*game;

    if (argc != 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
	game = create_game();
	if (!game)
		return (-1);
	game->map = get_map(fd);
    if (!(game->map) || !validate_map(game))
    {
        ft_putstr_fd("Error\n", 2);
		free_game(game);
        return (-1);
    }
	int i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	ft_printf("OK\n");
    return (1);
}
