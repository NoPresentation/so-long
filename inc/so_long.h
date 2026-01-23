/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:08 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/15 20:39:51 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

# define IMG_HEIGHT 64
# define IMG_WIDTH 64

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

typedef struct s_game
{
	/* Map data */
	char	**map;
	int		width;
	int		height;
	int		coins;
	int		pos_x;
	int		pos_y;
	int		exit_y;
	int		exit_x;
	int		exit_flag;
	int		dir;

	/* MLX core */
	void	*mlx;
	void	*win;

	/* Images */
	void	*wall_img;
	void	*floor_img;
	void	*pr;
	void	*pl;
	void	*exit_img;
	void	*coin_img;

	int		moves;
}			t_game;

// Map
char		**get_map(int fd);
void		render_map(t_game *game);
void		free_map(char **map);

// Map validation
int			validate_map(t_game *game);
int			check_rectangle(t_game *game);
int			check_walls(t_game *game);
int			check_chars(t_game *game);
int			check_components(t_game *game);
int			check_path(t_game *game);

// Game
t_game		*create_game(char **map);
void		fill_data_fields(t_game *game);
void		init_imgs(t_game *game);
void		start_game(t_game *game);
void		win_game(t_game *game);
int			close_game(t_game *game);

// MLX
void		fill_pixel(t_game *game, char tile, int x, int y);
int			load_images(t_game *game);
int			init_mlx(t_game *game);
void		*get_img(void *mlx, char *path, int *w, int *h);

// Moves
int			handle_key(int key_code, t_game *game);
void		try_move(t_game *game, int new_y, int new_x);

#endif