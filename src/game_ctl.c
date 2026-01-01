# include "so_long.h"

t_game *create_game()
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->height = 0;
	game->width = 0 ;
	game->position[0] = 0;
	game->position[0] = 1;
	game->collectables = 0;
	return (game);
}

bool correct_len(char *line, size_t len)
{
	size_t line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	if (line_len != len)
		return (false);
	return (true);
}

char	*read_map(int fd)
{
	char	*line;
	char	*reader;
	char	*temp;
	size_t	len;

	reader = ft_strdup("");
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	while (line)
	{
		if (!correct_len(line, len))
		{
			free(reader);
			free(line);
			return (NULL);
		}
		temp = reader;
		reader = ft_strjoin(reader, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	free(line);
	return (reader);
}

char **get_map(int fd)
{
	char	*reader;
	char	**map;

	if (fd == -1)
		return (NULL);
    reader = read_map(fd);
	if (!reader)
		return (NULL);
	map = ft_split(reader, '\n');
	free(reader);
	if (!map || map[0] == NULL)
		return (NULL);
	return (map);
}

void	*free_split(char **list, int elements)
{
	int	i;

	i = 0;
	while (i < elements)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_split(game->map, game->height);
	free(game);
}