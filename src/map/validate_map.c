/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:17 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/15 19:10:39 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_x = j;
				game->pos_y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
			}
			j++;
		}
		i++;
	}
}

int check_structure(t_game *game)
{
	if (!check_rectangle(game))
	{
		ft_putstr_fd("Error\nMap not a rectangle.\n", 2);
		return (0);
	}
	if (!check_walls(game))
	{
		ft_putstr_fd("Error\nInvalid map structure.\n", 2);
		return (0);
	}
	if (!check_chars(game))
	{
		ft_putstr_fd("Error\nFound invalid character.", 2);
		return (0);
	}
	if (!check_components(game))
	{
		ft_putstr_fd("Error\nExtra or missing characters.", 2);
		return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_structure(game))
		return (0);
	find_player_exit(game);
	if (!check_path(game))
	{
		ft_putstr_fd("Error\nMap has no valid path.\n", 2);
		return (0);
	}
	game->map[game->exit_y][game->exit_x] = '0';
	return (1);
}
