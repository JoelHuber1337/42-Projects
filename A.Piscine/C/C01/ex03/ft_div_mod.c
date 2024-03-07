/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:52:26 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/07 22:14:42 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int	main(void)
{
	int	div, mod, x, y;

	x = 18;
	y = 5;

	ft_div_mod(x, y, &div, &mod);
	printf("\n%d/%d = %d with rest of -> %d\n\n", x, y, div, mod);
}
*/
