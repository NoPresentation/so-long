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

void	*get_img(void *mlx, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, w, h);
	return (img);
}

void	fill_data_fields(t_game *game)
{
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
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	correct_len(char *line, int len)
{
	int line_len;

	if (!line)
		return (0);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	if (line_len != len)
		return (0);
	return (1);
}