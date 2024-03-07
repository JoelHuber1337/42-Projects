/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:13:19 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 21:13:20 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*x;
	int	range;
	int	i;

	range = max - min;
	x = (int *)malloc(range * sizeof(int));
	if (min >= max)
	{
		x = NULL;
		return (0);
	}
	i = 0;
	while (i < range)
	{
		x[i] = min + i;
		i++;
	}
	return (x);
}
