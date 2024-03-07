/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:24:32 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/26 20:24:35 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

int	ft_recursive_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	if (nb > 0)
		res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}
/*
int main(void)
{
	printf("%i", ft_recursive_factorial(6));
}
*/
