/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:16:48 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/07 22:33:17 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	swp;

	if (b != 0)
	{
		swp = *a;
		*a = swp / *b;
		*b = swp % *b;
	}
}

/*
int	main(void)
{
	int	a, b;
	
	a = 19;
	b = 5;
	printf("a=%d b=%d\n", a, b);
	printf("quotient=%d module=%d\n", a/b, a%b);
	ft_ultimate_div_mod(&a, &b);
	printf("-----From my func-------\n");
	printf("quotient=%d module=%d\n\n", a, b);
}
*/
