/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:17 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/31 14:37:54 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


int check_rectangle(t_game *game)
{
    size_t width;
    size_t i;

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

int check_walls(t_game *game)
{
    size_t i;
    size_t j;

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

int validate_map(t_game *game)
{
    // 1. Check that map is rectangle -> Width, Height [DONE!!]
    // 2. Check Walls [DONE!!]
    // 3. Check Escape, Collectable, Start -> Study
    // 4. Check Path -> Flood Fill
    if (!check_rectangle(game))
        return (0);
    if (!check_walls(game))
        return (0);
    
}