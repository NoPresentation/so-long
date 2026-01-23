/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:49:15 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/21 19:22:23 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd)
{
	char	*reader;
	char	**map;

	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid File Descriptor.\n", 2);
		return (NULL);
	}
	reader = read_map(fd);
	if (!reader)
		return (NULL);
	map = ft_split(reader, '\n');
	free(reader);
	if (!map || map[0] == NULL)
	{
		ft_putstr_fd("Error\nEmpty or invalid map.\n", 2);
		free_map(map);
		return (NULL);
	}
	return (map);
}
