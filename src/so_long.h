/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:08 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/26 19:43:45 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct s_game
{
    char    **map;
    size_t  width;
    size_t  height;
} t_game;

int     validate_map(t_game *game);


#endif