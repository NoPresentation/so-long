/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:13:43 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/08 21:55:10 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int is_valid_path(char **map, size_t width, size_t height)
{
    size_t	i;
    size_t	j;
    
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'C' || map[i][j] == 'E')
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void	flood_fill(char **map, size_t width, size_t height, size_t x, size_t y)
{
	if (x >= height || y >= width)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, width, height, x, y - 1);
	flood_fill(map, width, height, x, y + 1);
	flood_fill(map, width, height, x - 1, y);
	flood_fill(map, width, height, x + 1, y);
}

char	**copy_map(t_game *game)
{
	char	**map_copy;
	size_t	i;

	map_copy = malloc((game->height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_split(map_copy, i);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

int	check_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(
		map_copy,
		game->width,
		game->height,
		game->pos_x,
		game->pos_x
	);
	if (!is_valid_path(map_copy, game->width, game->height))
	{
		free_split(map_copy, game->height);
		return (0);
	}
	free_split(map_copy, game->height);
	return (1);
}
