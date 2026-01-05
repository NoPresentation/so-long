/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:34:41 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/05 17:38:58 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;

	game->win = mlx_new_window(
		game->mlx,
		game->width * IMG_WIDTH,
		game->height * IMG_HEIGHT,
		"So Long"
	);
	if (!game->win)
	{
		free(game->mlx);
		return ;
	}
}


int	game_start(t_game *game)
{
	init_mlx(game);
	if (!game->mlx || !game->win)
		return (0);
	
}