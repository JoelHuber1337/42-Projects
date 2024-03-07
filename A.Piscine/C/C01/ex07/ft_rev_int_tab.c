/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:12:45 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/11 11:14:06 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdlib.h>
#include <stdio.h>
*/
void	swap(int *p, int *p1);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swaps;

	i = 0;
	swaps = size / 2;
	while (swaps--)
		swap(&(tab[i++]), &(tab[--size]));
}

void	swap(int *p, int *p1)
{
	int	tmp;

	tmp = *p;
	*p = *p1;
	*p1 = tmp;
}

/*
int	main(void)
{
	int	v[20];

	for (int i=0; i<20; ++i)
		v[i] = rand()%101;

	printf("\nBEFORE\n");
	for (int i=0; i<20; i++)
		printf("%d ", v[i]);
	printf("\n");

	ft_rev_int_tab(v, sizeof(v)/sizeof(v[0]));

	printf("\nAFTER\n");
	for (int i=0; i<20; i++)
		printf("%d ", v[i]);
	printf("\n\n");
}
*/
