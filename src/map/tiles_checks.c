/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:49:44 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/08 17:12:46 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"


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
	game->coins = c;
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
