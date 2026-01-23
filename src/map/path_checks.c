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

static void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (y >= game->height || x >= game->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		game->coins--;
	if (map[y][x] == 'E')
		game->exit_flag = 1;
	map[y][x] = 'V';
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
}

static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((game->height + 1) * sizeof(char *));
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
	{
		ft_putstr_fd("Error\nMemory allocation error.\n", 2);
		return (0);
	}
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
