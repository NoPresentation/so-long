/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:34:41 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/08 23:09:51 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(
		game->mlx,
		game->width * IMG_WIDTH,
		game->height * IMG_HEIGHT,
		"So Long"
	);
	if (!game->win)
			return (0);
	return (1);
}

int	load_images(t_game *game)
{
	int w;
	int h;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "/home/ahmad_nashwan/core/so_long/imgs/border.xpm", &w, &h);
	if (!game->wall_img)
		return (0);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "/home/ahmad_nashwan/core/so_long/imgs/green.xpm", &w, &h);
	if (!game->floor_img)
		return (0);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "/home/ahmad_nashwan/core/so_long/imgs/bird.xpm", &w, &h);
	if (!game->player_img)
		return (0);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "/home/ahmad_nashwan/core/so_long/imgs/apple.xpm", &w, &h);
	if (!game->coin_img)
		return (0);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "/home/ahmad_nashwan/core/so_long/imgs/escape.xpm", &w, &h);
	if (!game->exit_img)
		return (0);
	return (1);
}

void fill_pixel( t_game *game, char tile, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x, y);
	else if (tile == 'E' && game->coins == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
}

void render_map(t_game *game)
{
	size_t		h;
	size_t		x;
	size_t		w;
	size_t		y;
	
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			x = w * IMG_WIDTH;
			y = h * IMG_HEIGHT;
			
			fill_pixel(game, game->map[h][w], x, y);
			w++;
		}
		h++;
	}
}

void	start_game(t_game *game)
{
	if (!init_mlx(game))
	{
		ft_putstr_fd("Game initialize failure.", 2);
		close_game(game);
	}
	if (!load_images(game))
	{
		ft_putstr_fd("Failed to load images!", 2);
		close_game(game);
	}
	render_map(game);

	/* 
	   FIX: Double cast strategy
	   1. (void *)       -> generic pointer (breaks the function type chain)
	   2. (int (*)(void)) -> the target type MLX expects
	*/
	mlx_hook(game->win, 2, 1L << 0, (int (*)(void))(void *)handle_key, game);
	mlx_hook(game->win, 17, 0, (int (*)(void))(void *)close_game, game);

	mlx_loop(game->mlx);
}
