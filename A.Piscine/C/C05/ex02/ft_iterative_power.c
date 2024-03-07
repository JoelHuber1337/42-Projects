/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:25:28 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 11:25:29 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	
#include <stdio.h>
*/
int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	if (power == 0)
		res = 1;
	else if (power < 0)
		res = 0;
	return (res);
}
/*
int	main(void)
{
	printf("%i", ft_iterative_power(10, 4));
}
*/
