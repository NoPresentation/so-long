/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:34:41 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/09 02:59:09 by anashwan         ###   ########.fr       */
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

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./imgs/border.xpm", &w,
			&h);
	if (!game->wall_img)
		return (0);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./imgs/green.xpm", &w,
			&h);
	if (!game->floor_img)
		return (0);
	game->p_right = mlx_xpm_file_to_image(game->mlx, "./imgs/bird_right.xpm",
			&w, &h);
	if (!game->p_right)
		return (0);
	game->p_left = mlx_xpm_file_to_image(game->mlx, "./imgs/bird_left.xpm", &w,
			&h);
	if (!game->p_left)
		return (0);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "./imgs/apple.xpm", &w,
			&h);
	if (!game->coin_img)
		return (0);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./imgs/escape.xpm", &w,
			&h);
	if (!game->exit_img)
		return (0);
	return (1);
}

void	fill_pixel(t_game *game, char tile, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x, y);
	else if (tile == 'P' && game->dir == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->p_right, x, y);
	else if (tile == 'P' && game->dir == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->p_left, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x, y);
	else if (tile == 'E' && game->coins == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
}

void	render_map(t_game *game)
{
	size_t	h;
	size_t	x;
	size_t	w;
	size_t	y;

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
		ft_putstr_fd("Game initialize failure.", 2);
		close_game(game);
	}
	if (game && !load_images(game))
	{
		ft_putstr_fd("Failed to load images!", 2);
		close_game(game);
	}
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, (int (*)(void))(void *)handle_key, game);
	mlx_hook(game->win, 17, 0, (int (*)(void))(void *)close_game, game);
	mlx_loop(game->mlx);
}
