/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:09:19 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 12:09:31 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_sqrt_rec(int nb, int n)
{
	if (nb > n * n && n < 46341)
		return (ft_sqrt_rec(nb, n + 1));
	if (n * n == nb)
		return (n);
	else
		return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_rec(nb, 0));
}
/*
int main(void)
{
	printf("%i", ft_sqrt(4));
}
*/
