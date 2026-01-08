/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:52:21 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/08 21:14:14 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

t_game *create_game(char **map)
{
	t_game *game;

	if (!map)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->height = 0;
	game->width = 0 ;
	game->mlx = NULL;
	game->win = NULL;
	game->pos_x = 0;
	game->pos_y = 0;
	game->exit_y = 0;
	game->exit_x = 0;
	game->coins = 0;
	game->moves = 0;
	game->floor_img = NULL;
	game->coin_img = NULL;
	game->wall_img = NULL;
	game->exit_img = NULL;
	game->player_img = NULL;
	return (game);
}

void	win_game(t_game *game)
{
	ft_putstr_fd("YOU WON!!\nMOVES: %d\n", game->moves);
	close_game(game);
}

int close_game(void *ptr)
{
	t_game *game;

	game =(t_game *)ptr;
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlx, game->floor_img);
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->coin_img)
        mlx_destroy_image(game->mlx, game->coin_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->map)
        free_split(game->map, game->height); 
    exit(0);
    return (0);
}
