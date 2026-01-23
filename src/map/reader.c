/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:34:19 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/23 16:34:20 by anashwan         ###   ########.fr       */
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

static void	free_reader(int fd, char *reader, char *line)
{
	if (reader)
		free(reader);
	if (line)
		free(line);
	if (fd != -1)
		free_gnl(fd);
}

static int	check_reader(char *reader, char *line, size_t len)
{
	if (!reader)
	{
		ft_putstr_fd("Error\nCouldn't read map.\n", 2);
		return (-1);
	}
	if (!correct_len(line, len))
	{
		ft_putstr_fd("Error\nMap not rectangular.\n", 2);
		return (-2);
	}
	return (1);
}

static int	append_and_check(char **reader, char *line, size_t len)
{
	char	*temp;
	int		check;

	temp = *reader;
	*reader = ft_strjoin(*reader, line);
	if (!*reader)
	{
		free(temp);
		return (-1);
	}
	check = check_reader(*reader, line, len);
	free(temp);
	return (check);
}

char	*read_map(int fd)
{
	char	*line;
	char	*reader;
	int		check;
	size_t	len;

	reader = ft_strdup("");
	line = get_next_line(fd);
	if (!reader || !line)
	{
		ft_putstr_fd("Error\nCouldn't read from file.\n", 2);
		return (NULL);
	}
	len = ft_strlen(line) - 1;
	while (line)
	{
		check = append_and_check(&reader, line, len);
		if (check == -1 || check == -2)
		{
			free_reader(fd, reader, line);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (reader);
}
