/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:52:45 by anashwan          #+#    #+#             */
/*   Updated: 2025/11/25 21:07:38 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new)
{
	t_gnl_list	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_gnl_list	*gnl_lstnew(char *content)
{
	t_gnl_list	*element;
	int		i;
	char	*string;

	if (!content)
		return (NULL);
	element = malloc(sizeof(t_gnl_list));
	if (!element)
		return (NULL);
	i = 0;
	while (content[i])
		i++;
	string = malloc(i + 1);
	if (!string)
	{
		free(element);
		return (NULL);
	}
	gnl_strlcpy(string, content, i + 1);
	element->content = string;
	element->next = NULL;
	return (element);
}

void	*gnl_lstclear(t_gnl_list **lst, void (*del)(void *), char *buffer)
{
	t_gnl_list	*next;

	if (buffer)
		free(buffer);
	if (!lst || !(*lst) || !del)
		return (NULL);
	while (*lst)
	{
		del((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		(*lst) = next;
	}
	*lst = NULL;
	return (NULL);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	gnl_line_len(t_gnl_list **list)
{
	t_gnl_list	*node;
	size_t	i;
	size_t	len;

	if (!list || !*list)
		return (0);
	node = *list;
	len = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		node = node->next;
	}
	return (len);
}
