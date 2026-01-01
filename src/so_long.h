/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:08:08 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/01 20:39:54 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct s_game
{
    char    **map;
    size_t  width;
    size_t  height;
    size_t  collectables;
    size_t  position[2];
} t_game;

int     validate_map(t_game *game);
void	free_game(t_game *game);
int	    check_rectangle(t_game *game);
int	    check_walls(t_game *game);
void	flood_fill(char **map, size_t width, size_t height, int x, int y);
int     is_valid_path(char **map, size_t width, size_t height);
int     check_path(t_game *game);
int	    count_occurance(const char *s, char c);
void	find_player(t_game *game);
int	    check_components(t_game *game);
int     check_chars(t_game *game);
int     validate_map(t_game *game);
t_game *create_game(char **map);
char    **get_map(int fd);
void	free_game(t_game *game);
void	*free_split(char **list, int elements);
char	*read_map(int fd);
#endif