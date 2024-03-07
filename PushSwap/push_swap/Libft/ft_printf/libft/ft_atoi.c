/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:13:28 by jhuber            #+#    #+#             */
/*   Updated: 2024/01/30 21:32:45 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi1(const char *nptr)
{
	int	result;
	int	sign;
	int	x;

	result = 0;
	sign = 1;
	x = 0;
	while (nptr[x] == ' ' || nptr[x] == '\t' || nptr[x] == '\n'
		|| nptr[x] == '\v' || nptr[x] == '\f' || nptr[x] == '\r')
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x] == '-')
			sign *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		result = result * 10 + (nptr[x] - '0');
		x++;
	}
	return (result * sign);
}
