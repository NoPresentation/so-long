/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:28:30 by anashwan          #+#    #+#             */
/*   Updated: 2025/09/15 23:28:59 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_f(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
		return (write(1, "-", 1) + ft_putnbr_base((n * -1), 10, 'a'));
	return (ft_putnbr_base(n, 10, 'a'));
}

int	ft_unsigned_f(unsigned int n)
{
	return (ft_putnbr_base(n, 10, 'a'));
}

int	ft_hexa_f(unsigned int n, char hex)
{
	if (hex == 'x')
		hex = 'a';
	else
		hex = 'A';
	return (ft_putnbr_base(n, 16, hex));
}

int	ft_ptr_f(void *p)
{
	if (!p)
		return (ft_str_f("(nil)"));
	return (ft_str_f("0x") + ft_putnbr_base((unsigned long)p, 16, 'a'));
}

int	ft_char_f(char c)
{
	return (write(1, &c, 1));
}
