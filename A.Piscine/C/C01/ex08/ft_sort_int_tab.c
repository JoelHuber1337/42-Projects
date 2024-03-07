/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:00:07 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/11 19:00:14 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
#include <stdlib.h>
*/
void	swap(int *n, int *n1);
void	ft_sort_int_tab(int *tab, int size);
/*
int main()
{
	int v[100];
	int i = 0;

	printf("\nBefore Sorting\n\n");
	while (i<100)
	{
		v[i] = rand()%1001-500;
		printf("%d ", v[i]);
		i++;
	}
	ft_sort_int_tab(v, 100);

	printf("\nAfter Sorting\n\n");
	i = 0;
	while (i<100)
	{
		printf("%d ", v[i]);
		i++;
	}
	printf("\n\n\n");
}
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		i++;
		while (j < size -1)
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
	}
}

void	swap(int *n, int *n1)
{
	int	tmp;

	tmp = *n;
	*n = *n1;
	*n1 = tmp;
}
