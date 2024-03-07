/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:52:27 by jhuber            #+#    #+#             */
/*   Updated: 2023/10/06 23:13:53 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printv(va_list args, char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_puthex(va_arg(args, unsigned int), str);
	else if (str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		x;
	int		y;

	va_start(args, str);
	if (str == 0)
		return (-1);
	x = 0;
	y = 0;
	while (str[x])
	{
		if (str[x] == '%' && str[++x])
		{
			y += printv(args, str[x]);
			x++;
		}
		if (str[x] != '%' && str[x])
		{
			y += ft_putchar(str[x]);
			x++;
		}
	}
	va_end(args);
	return (y);
}
