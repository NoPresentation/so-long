/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:07:05 by anashwan          #+#    #+#             */
/*   Updated: 2025/09/15 22:43:11 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_str_f(const char *s);
int	ft_putnbr_base(unsigned long n, int base, char hex);
// Wrapper functions
int	ft_digit_f(int n);
int	ft_unsigned_f(unsigned int n);
int	ft_hexa_f(unsigned int n, char hex);
int	ft_ptr_f(void *p);
int	ft_char_f(char c);

#endif