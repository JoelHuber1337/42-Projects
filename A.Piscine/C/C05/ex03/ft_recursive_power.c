/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:46:23 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 11:46:24 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power > 1)
		res *= ft_recursive_power(nb, power - 1);
	else if (power == 0)
		res = 1;
	else if (power < 0)
		res = 0;
	return (res);
}
/*
int main(void)
{
	printf("%i", ft_recursive_power(3917, -1370));
}
*/
