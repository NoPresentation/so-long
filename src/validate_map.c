/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:17 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/01 18:45:03 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_game *game)
{
	size_t	width;
	size_t	i;

	width = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != width)
			return (0);
		i++;
	}
	game->height = i;
	game->width = width;
	return (1);
}

int	check_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(char **map, size_t width, size_t height, int x, int y)
{
	if (x < 0 || x >= (int)height || y < 0 || y >= (int)width)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, width, height, x, y - 1);
	flood_fill(map, width, height, x, y + 1);
	flood_fill(map, width, height, x - 1, y);
	flood_fill(map, width, height, x + 1, y);
}

int is_valid_path(char **map, size_t width, size_t height)
{
    size_t	i;
    size_t	j;
    
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'C' || map[i][j] == 'E')
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int check_path(t_game *game)
{
    char 	**map_copy;
    size_t	i;

    map_copy = malloc((game->height + 1) * sizeof(char *));
    if (!map_copy)
        return (0);
    i = 0;
    while (i < game->height)
    {
        map_copy[i] = ft_strdup(game->map[i]);
        if (!map_copy[i])
        {
            free_game(game);
            return (0);
        }
		i++;
    }
    map_copy[game->height] = NULL;
    flood_fill(map_copy, game->width, game->height,
               game->position[0], game->position[1]);
    if (!is_valid_path(map_copy, game->width, game->height))
	{
		free_game(game);
        return (0);
	}
	free_split(map_copy, game->height);
	return (1);
}

int	count_occurance(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->position[0] = i;
				game->position[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_components(t_game *game)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (game->map[i])
	{
		p += count_occurance(game->map[i], 'P');
		e += count_occurance(game->map[i], 'E');
		c += count_occurance(game->map[i], 'C');
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);
	game->collectables = c;
	return (1);
}

int check_chars(t_game *game)
{
    size_t	i;
    size_t	j;
    char	**map;

    i = 0;
    map = game->map;
    while (i < game->height)
    {
        j = 0;
        while (j < game->width)
        {
            if (map[i][j] != '1' && map[i][j] != '0' &&
                map[i][j] != 'P' && map[i][j] != 'E' &&
                map[i][j] != 'C' )
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int	validate_map(t_game *game)
{
	// 1. Check that map is rectangle -> Width, Height [DONE!!]
	// 2. Check Walls [DONE!!]
	// 2.2 Check esc, coins, playes [DONE!!]
	// 3. Check Escape, Collectables, and player [DONE!!]
	// 4. Check Path -> Flood Fill [DONE!!]
	if (!check_rectangle(game))
		return (0);
    if (!check_walls(game))
		return (0);
	if (!check_chars(game))
		return (0);
	if (!check_components(game))
		return (0);
	find_player(game);
	if (!check_path(game))
		return (0);
	// play_game(game);
    return (1);
}
