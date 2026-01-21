/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 01:13:43 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/15 20:25:26 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_game *game, size_t x, size_t y)
{
	if (x >= game->height || y >= game->width)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'C')
		game->coins--;
	if (map[x][y] == 'E')
		game->exit_flag = 1;
	map[x][y] = 'V';
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
}

char	**copy_map(t_game *game)
{
	char	**map_copy;
	size_t	i;

	map_copy = malloc((game->height + 1) * sizeof(char *) + 1);
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[game->height] = NULL;
	return (map_copy);
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int		holder;

	map_copy = copy_map(game);
	holder = game->coins;
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game, game->pos_x, game->pos_y);
	if (game->coins != 0 || !game->exit_flag)
	{
		free_map(map_copy);
		ft_putstr_fd("Error\nMap has no valid path.\n", 2);
		return (0);
	}
	game->coins = holder;
	free_map(map_copy);
	return (1);
}
