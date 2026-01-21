/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:52:21 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/15 20:22:02 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_game *game)
{
	game->floor_img = NULL;
	game->coin_img = NULL;
	game->wall_img = NULL;
	game->exit_img = NULL;
	game->pl = NULL;
	game->pr = NULL;
}

void	free_images(t_game *game)
{
	if (game->pr)
		mlx_destroy_image(game->mlx, game->pr);
	if (game->pl)
		mlx_destroy_image(game->mlx, game->pl);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->coin_img)
		mlx_destroy_image(game->mlx, game->coin_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
}

t_game	*create_game(char **map)
{
	t_game	*game;

	if (!map)
		return (NULL);
	game = malloc(sizeof(t_game)); // note: if game is NULL // leaks were found
	if (!game)
	{
		free_map(map);
		return (NULL);
	}
	game->map = map;
	game->height = 0;
	game->width = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->pos_x = 0;
	game->pos_y = 0;
	game->exit_y = 0;
	game->exit_x = 0;
	game->coins = 0;
	game->moves = 0;
	game->dir = 1;
	game->exit_flag = 0;
	init_imgs(game);
	return (game);
}

void	win_game(t_game *game)
{
	ft_putstr_fd("YOU WON!!\n", 1);
	close_game(game);
}

int	close_game(t_game *game)
{
	if (!game)
		return (0);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map);
	free_images(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	game = NULL;
	exit(0);
}

// 2 Erros are being printed
// Error
// Map must have at least one collectable.
// Error
// Map must have one player and one exit ONLY!