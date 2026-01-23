/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:46:59 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/10 17:17:58 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == '1')
		return ;
	try_move(game, game->pos_y - 1, game->pos_x);
}

static void	move_down(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == '1')
		return ;
	try_move(game, game->pos_y + 1, game->pos_x);
}

static void	move_left(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == '1')
		return ;
	try_move(game, game->pos_y, game->pos_x - 1);
}

static void	move_right(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == '1')
		return ;
	try_move(game, game->pos_y, game->pos_x + 1);
}

int	handle_key(int key_code, t_game *game)
{
	if (key_code == W || key_code == UP)
		move_up(game);
	else if (key_code == S || key_code == DOWN)
		move_down(game);
	else if (key_code == D || key_code == RIGHT)
	{
		game->dir = 1;
		move_right(game);
	}
	else if (key_code == A || key_code == LEFT)
	{
		game->dir = 0;
		move_left(game);
	}
	else if (key_code == KEY_ESC || key_code == KEY_Q)
		close_game(game);
	return (0);
}
