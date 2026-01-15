/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:49:15 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/15 20:17:14 by anashwan         ###   ########.fr       */
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
		return (false);
	return (true);
}

char	*read_map(int fd)
{
	char	*line;
	char	*reader;
	char	*temp;
	//size_t	len;

	reader = ft_strdup("");
	line = get_next_line(fd);
	//len = ft_strlen(line) - 1;
	while (line)
	{
		// if (!correct_len(line, len))
		// {
		// 	free(reader);
		// 	free(line);
		// 	ft_putstr_fd("Error\nLines are not the same length.\n", 2);
		// 	return (NULL);
		// }
		temp = reader;
		reader = ft_strjoin(reader, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	free(line);
	return (reader);
}

void    free_map(char **list)
{
    int i;

    if (!list)
        return;
    i = 0;
    while (list[i])
    {
        free(list[i]);
        i++;
    }
    free(list);
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
		ft_putstr_fd("Error\nFailed to read the map.\n", 2);
		return (NULL);
	}
	map = ft_split(reader, '\n');
	free(reader);
	if (!map || map[0] == NULL)
	{
		ft_putstr_fd("Error\nEmpty or non-existing map.\n", 2);
		return (NULL);
	}
	close(fd);
	return (map);
}
