/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:34:41 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/21 20:38:37 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * IMG_WIDTH, game->height
			* IMG_HEIGHT, "So Long");
	if (!game->win)
		return (0);
	return (1);
}

int	load_images(t_game *game)
{
	int	w;
	int	h;

	game->wall_img = get_img(game->mlx, "./imgs/border.xpm", &w, &h);
	game->floor_img = get_img(game->mlx, "./imgs/green.xpm", &w, &h);
	game->pr = get_img(game->mlx, "./imgs/bird_right.xpm", &w, &h);
	game->pl = get_img(game->mlx, "./imgs/bird_left.xpm", &w, &h);
	game->coin_img = get_img(game->mlx, "./imgs/apple.xpm", &w, &h);
	game->exit_img = get_img(game->mlx, "./imgs/escape.xpm", &w, &h);
	if (!game->wall_img || !game->floor_img || !game->pr || !game->pl
		|| !game->coin_img || !game->exit_img)
		return (0);
	return (1);
}

void	fill_pixel(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x, y);
	else if (tile == 'P' && game->dir == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->pr, x, y);
	else if (tile == 'P' && game->dir == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->pl, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x, y);
	else if (tile == 'E' && game->coins == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
}

void	render_map(t_game *game)
{
	int	h;
	int	x;
	int	w;
	int	y;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			x = w * 64;
			y = h * 64;
			fill_pixel(game, game->map[h][w], x, y);
			w++;
		}
		h++;
	}
}

void	start_game(t_game *game)
{
	if (game && !init_mlx(game))
	{
		ft_putstr_fd("Error\nGame initialize failure.\n", 2);
		close_game(game);
	}
	if (game && !load_images(game))
	{
		ft_putstr_fd("Error\nFailed to load images!\n", 2);
		close_game(game);
	}
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
