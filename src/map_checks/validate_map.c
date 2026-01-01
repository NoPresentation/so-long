/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:17 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/02 01:16:03 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_game *game)
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
				game->position[0] = i;
				game->position[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	validate_map(t_game *game)
{
	if (!check_rectangle(game))
		return (0);
    if (!check_walls(game))
		return (0);
	if (!check_chars(game))
		return (0);
	if (!check_components(game))
		return (0);
	find_player(game);
	if (!check_path(game))
		return (0);
	// play_game(game);
    return (1);
}
