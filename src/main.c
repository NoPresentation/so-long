# include "so_long.h"

char **get_map(int fd)
{
    char    *holder;
    char    *line;
	char	*temp;
	char	**map;

	if (fd == -1)
		return (NULL);
    holder = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = holder;
		holder = ft_strjoin(holder, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	map = ft_split(holder, '\n');
	free(holder);
	if (!map || map[0] == NULL)
		return (NULL);
	return (map);
}

int main(int argc, char **argv)
{
    int     fd;
    char    **map;
	t_game	*game;

    if (argc != 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    game->map = get_map(fd);
    if (!validate_map(game))
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
    
}
