/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:52:21 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/21 20:43:42 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*create_game(char **map)
{
	t_game	*game;

	if (!map)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error\nFailed allocation of memory for game.\n", 2);
		free_map(map);
		return (NULL);
	}
	game->map = map;
	fill_data_fields(game);
	init_imgs(game);
	return (game);
}

void	win_game(t_game *game)
{
	ft_putstr_fd("YOU WON!!\n", 1);
	close_game(game);
}

static void	free_images(t_game *game)
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
