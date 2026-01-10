/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:08 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/10 18:27:38 by anashwan         ###   ########.fr       */
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
	size_t	width;
	size_t	height;
	size_t	coins;
	size_t	pos_x;
	size_t	pos_y;
	size_t	exit_x;
	size_t	exit_y;
	int		dir;

	/* MLX core */
	void	*mlx;
	void	*win;

	/* Images */
	void	*wall_img;
	void	*floor_img;
	void	*p_right;
	void	*p_left;
	void	*exit_img;
	void	*coin_img;

	size_t	moves;
}			t_game;


// Checks
int			validate_map(t_game *game);
int			check_structure(t_game *game);
int			check_rectangle(t_game *game);
int			check_walls(t_game *game);
int			is_valid_path(char **map, size_t width, size_t height);
int			check_path(t_game *game);
int			count_occurance(const char *s, char c);
void		find_player(t_game *game);
int			check_components(t_game *game);
int			check_chars(t_game *game);

// Get map
char		**get_map(int fd);
void		*free_split(char **list, int elements);
char		*read_map(int fd);

// Game Start
t_game		*create_game(char **map);
void		start_game(t_game *game);
int			init_mlx(t_game *game);
int			load_images(t_game *game);
void		render_map(t_game *game);
void		flood_fill(char **map, size_t width, size_t height, size_t x,
				size_t y);

// Movement and Events
int			handle_key(int key_code, void *ptr);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		try_move(t_game *game, size_t new_y, size_t new_x);

// Game end
void		close_game(t_game *game);
void		win_game(t_game *game);
#endif