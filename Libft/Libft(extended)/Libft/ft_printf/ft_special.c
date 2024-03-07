/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 01:19:56 by jhuber            #+#    #+#             */
/*   Updated: 2023/10/06 23:41:45 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	x;

	x = 0;
	if (str == 0)
		return (write(1, "(null)", 6));
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
	return (x);
}

int	ft_putnbr(int n)
{
	char	*nb;
	int		len;

	len = 0;
	nb = ft_itoa(n);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}

int	ft_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	if (n > 9)
	{
		len += ft_unsigned(n / 10);
		len += ft_unsigned(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
