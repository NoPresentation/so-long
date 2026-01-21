/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:33:15 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/15 20:36:15 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_move(t_game *game, size_t new_y, size_t new_x)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->coins -= 1;
	}
	if (game->map[new_y][new_x] == 'E')
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		win_game(game);
		return ;
	}
	game->map[game->pos_y][game->pos_x] = '0';
	if (game->coins == 0)
		game->map[game->exit_y][game->exit_x] = 'E';
	game->map[new_y][new_x] = 'P';
	game->pos_y = new_y;
	game->pos_x = new_x;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
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
