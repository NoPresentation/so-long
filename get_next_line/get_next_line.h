/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad_nashwan <ahmad_nashwan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:53:05 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/26 18:11:04 by ahmad_nashw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str
{
	char			*content;
	struct s_str	*next;
}					t_str;

char				*get_next_line(int fd);
void				gnl_lstadd_back(t_str **lst, t_str *new);
t_str				*gnl_lstnew(char *content);
void				*gnl_lstclear(t_str **lst, void (*del)(void *),
						char *buffer);
size_t				gnl_strlcpy(char *dest, const char *src, size_t size);
size_t				gnl_line_len(t_str **list);

#endif
