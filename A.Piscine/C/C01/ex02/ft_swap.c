/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:51:24 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/07 18:46:53 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*
int    main(void)
{
    int	x, y;

    x = 10;
    y = 42;
    printf("before\n %d %d\n", x, y);
    ft_swap(&x, &y);
    printf("after\n %d %d\n", x, y);
}
*/
