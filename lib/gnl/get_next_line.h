/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:53:05 by anashwan          #+#    #+#             */
/*   Updated: 2025/11/25 21:07:36 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct gnl_list
{
	char			*content;
	struct gnl_list	*next;
}					t_gnl_list;

char				*get_next_line(int fd);

void				gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new);
t_gnl_list			*gnl_lstnew(char *content);
void				*gnl_lstclear(t_gnl_list **lst, void (*del)(void *),
						char *buffer);
size_t				gnl_strlcpy(char *dest, const char *src, size_t size);
size_t				gnl_line_len(t_gnl_list **list);

#endif
