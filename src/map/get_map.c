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



bool	correct_len(char *line, size_t len)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	if (line_len != len)
	{
		ft_putstr_fd("Error\nLines are not the same length.\n", 2);
		return (false);
	}
	return (true);
}

char	*read_map(int fd)
{
	char	*line;
	char	*reader;
	char	*temp;

	reader = ft_strdup(""); // CHECKED
	if (!reader)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = reader;
		reader = ft_strjoin(reader, line); // No leak, still reachable
		if (!reader)
		{
			free(line);
			free(temp);
			return (NULL);
		}
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	free(line);
	return (reader);
}

void    free_map(char **map)
{
    int i;

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
	{
		ft_putstr_fd("Error\nCouldn't read from file.\n", 2);
		return (NULL);
	}
	map = ft_split(reader, '\n'); // Checked
	free(reader);
	if (!map || map[0] == NULL)
	{
		ft_putstr_fd("Error\nEmpty or invalid map.\n", 2);
		free_map(map);
		return (NULL);
	}
	return (map);
}
