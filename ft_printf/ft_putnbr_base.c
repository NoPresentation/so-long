/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:25:59 by anashwan          #+#    #+#             */
/*   Updated: 2025/09/15 23:28:59 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, int base, char hex)
{
	char	digit;
	int		count;

	count = 0;
	if (n / base != 0)
		count += ft_putnbr_base(n / base, base, hex);
	digit = (n % base);
	if (digit < 10)
		digit += '0';
	else
		digit += (hex - 10);
	count += write(1, &digit, 1);
	return (count);
}
