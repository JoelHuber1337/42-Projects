/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:13:40 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 21:13:41 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*x;
	int	total;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	total = max - min;
	x = (int *)malloc(total * sizeof(int));
	if (x == NULL)
		return (-1);
	i = 0;
	while (i < total)
	{
		x[i] = min + i;
		i++;
	}
	*range = x;
	return (total);
}
