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

static void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static int	correct_len(char *line, int len)
{
	int	line_len;

	if (!line)
		return (0);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	if (line_len != len)
		return (0);
	return (1);
}

static void	free_reader(int fd, char *reader, char *line, char *temp)
{
	if (reader)
		free(reader);
	if (line)
		free(line);
	if (temp)
		free(temp);
	if (fd != -1)
		free_gnl(fd);
}

static char	*read_map(int fd)
{
	char	*line;
	char	*reader;
	char	*temp;
	size_t	len;

	reader = ft_strdup("");
	if (!reader)
		return (NULL);
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	while (line)
	{
		temp = reader;
		reader = ft_strjoin(reader, line);
		if (!reader || !correct_len(line, len))
		{
			free_reader(fd, reader, line, temp);
			return (NULL);
		}
		free_reader(-1, NULL, line, temp);
		line = get_next_line(fd);
	}
	free(line);
	return (reader);
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
		ft_putstr_fd("Error\nLine length error (Possible memory allocation )\n",
			2);
		return (NULL);
	}
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
