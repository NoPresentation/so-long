/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:36:27 by anashwan          #+#    #+#             */
/*   Updated: 2025/11/25 21:07:37 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*polish_list(t_gnl_list **list, t_gnl_list *node, size_t index, int eof)
{
	char	*last_string;
	size_t	i;
	t_gnl_list	*last_node;

	i = 0;
	if (eof || !list || !node || !(node->content[index]))
		return (gnl_lstclear(list, free, NULL));
	while (node->content[index + i] != '\0')
		i++;
	last_string = malloc(i + 1);
	if (!last_string)
		return (gnl_lstclear(list, free, NULL));
	i = 0;
	while (node->content[index] != '\0')
		last_string[i++] = node->content[index++];
	last_string[i] = '\0';
	last_node = gnl_lstnew(last_string);
	if (!last_node)
		return (gnl_lstclear(list, free, NULL));
	gnl_lstclear(list, free, NULL);
	gnl_lstadd_back(list, last_node);
	free(last_string);
	return (NULL);
}

static char	*get_line_from_node(t_gnl_list **list, int eof)
{
	char	*line;
	size_t	j;
	size_t	index;
	t_gnl_list	*node;

	line = malloc(gnl_line_len(list) + 1);
	if (!list || !(*list) || !line)
		return ((char *)gnl_lstclear(list, free, NULL));
	index = 0;
	node = *list;
	while (node)
	{
		j = 0;
		while (node->content[j] && node->content[j] != '\n')
			line[index++] = node->content[j++];
		if (node->content[j] == '\n')
		{
			line[index++] = node->content[j++];
			break ;
		}
		node = node->next;
	}
	line[index] = '\0';
	polish_list(list, node, j, eof);
	return (line);
}

static int	process_line(char *buffer, t_gnl_list **list)
{
	ssize_t	i;
	t_gnl_list	*new_node;

	i = 0;
	new_node = gnl_lstnew(buffer);
	if (!new_node)
		return (-1);
	while (new_node->content[i])
	{
		if (new_node->content[i] == '\n')
		{
			gnl_lstadd_back(list, new_node);
			free(buffer);
			return (1);
		}
		i++;
	}
	gnl_lstadd_back(list, new_node);
	return (0);
}

static char	*search_for_line(int fd, t_gnl_list **list)
{
	char	*buffer;
	ssize_t	bytes;
	int		check;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!list || !buffer)
		return ((char *)gnl_lstclear(list, free, buffer));
	bytes = read(fd, buffer, BUFFER_SIZE);
	check = 0;
	while (bytes)
	{
		if (bytes == -1)
			return ((char *)gnl_lstclear(list, free, buffer));
		buffer[bytes] = '\0';
		check = process_line(buffer, list);
		if (check == -1)
			return ((char *)gnl_lstclear(list, free, buffer));
		if (check)
			return (get_line_from_node(list, 0));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (!list || !(*list))
		return ((char *)gnl_lstclear(list, free, NULL));
	return (get_line_from_node(list, 1));
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	t_gnl_list			*node;
	int				i;
	char			*line;

	node = list;
	if (BUFFER_SIZE < 0 || fd < 0)
		return ((char *)gnl_lstclear(&list, free, NULL));
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == '\n')
			{
				line = get_line_from_node(&list, 0);
				return (line);
			}
			i++;
		}
		node = node->next;
	}
	line = search_for_line(fd, &list);
	return (line);
}
