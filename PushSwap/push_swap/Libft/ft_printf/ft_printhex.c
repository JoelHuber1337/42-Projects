/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:49:00 by jhuber            #+#    #+#             */
/*   Updated: 2023/10/06 18:32:48 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long long int n, char format)
{
	int	result;

	result = 0;
	if (n > 15)
	{
		result += ft_puthex_ptr(n / 16, format);
		result += ft_puthex_ptr(n % 16, format);
	}
	else
	{
		if (format == 'x')
			result += ft_putchar("0123456789abcdef"[n % 16]);
		else if (format == 'X')
			result += ft_putchar("0123456789ABCDEF"[n % 16]);
	}
	return (result);
}

int	ft_putptr(void *p)
{
	int						result;
	unsigned long long int	ptr;

	result = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	ptr = (unsigned long long int)p;
	result += write(1, "0x", 2);
	result += ft_puthex_ptr(ptr, 'x');
	return (result);
}

int	ft_puthex(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_puthex(n / 16, format);
		len += ft_puthex(n % 16, format);
	}
	else
	{
		if (format == 'x')
			len += ft_putchar("0123456789abcdef"[n % 16]);
		else if (format == 'X')
			len += ft_putchar("0123456789ABCDEF"[n % 16]);
	}
	return (len);
}
