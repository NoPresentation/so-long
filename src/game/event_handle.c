/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:33:15 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/08 21:11:11 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	try_move(t_game *game, size_t new_y, size_t new_x)
{
	if (game->map[new_y][new_x] == 'C')
		game->coins -= 1;
	if (game->map[new_y][new_x] == 'E' && game->coins == 0)
	{
		win_game(game);
		return ;
	}
	if (game->coins == 0)
		game->map[game->exit_y][game->exit_x] = 'E';
	game->map[game->pos_y][game->pos_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->pos_y = new_y;
	game->pos_x = new_x;
	game->moves++;
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

int	handle_key(int key_code, void *ptr)
{
	t_game *game = (t_game *)ptr;
	if (key_code == KEY_UP || key_code == FRONT)
		move_up(game);
	else if (key_code == KEY_DOWN || key_code == BACK)
		move_down(game);
	else if (key_code == KEY_RIGHT || key_code == RIGHT)
		move_right(game);
	else if (key_code == KEY_LEFT || key_code == LEFT)
		move_left(game);
	else if (key_code == KEY_ESC || key_code == KEY_Q)
		close_game(game);
	return (0);
}