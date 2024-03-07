/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:12:56 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/11 19:43:14 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strset(int n)
{
	int	x;

	x = 1;
	if (n < 0)
		x++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				x;
	unsigned int	nbr;

	x = strset(n);
	str = (char *)malloc((x + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[x--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	str[x--] = nbr % 10 + '0';
	while (nbr > 9)
	{
		nbr /= 10;
		str[x--] = nbr % 10 + '0';
	}
	return (str);
}
