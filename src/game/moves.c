/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:46:59 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/08 20:47:14 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == '1')
		return ;
	try_move(game, game->pos_y - 1, game->pos_x);
}

void	move_down(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == '1')
		return ;
	try_move(game, game->pos_y + 1, game->pos_x);
}

void	move_left(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == '1')
		return ;
	try_move(game, game->pos_y, game->pos_x - 1);
}

void	move_right(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == '1')
		return ;
	try_move(game, game->pos_y, game->pos_x + 1);
}