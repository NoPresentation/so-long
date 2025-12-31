/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:11:46 by anashwan          #+#    #+#             */
/*   Updated: 2025/09/16 00:59:05 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_handler(va_list list, char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_str_f(va_arg(list, char *));
	else if (c == 'c')
		count += ft_char_f(va_arg(list, int));
	else if (c == 'd' || c == 'i')
		count += ft_digit_f(va_arg(list, int));
	else if (c == 'u')
		count += ft_unsigned_f(va_arg(list, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_hexa_f(va_arg(list, unsigned int), c);
	else if (c == 'p')
		count += ft_ptr_f(va_arg(list, void *));
	else if (c == '%')
		count += ft_char_f(c);
	else
		count = -1;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		count;
	int		i;
	int		check;

	count = 0;
	i = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			check = format_handler(list, s[i]);
			if (check == -1)
				return (-1);
			else
				count += check;
		}
		else
			count += ft_char_f(s[i]);
		i++;
	}
	va_end(list);
	return (count);
}
