/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:39:03 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/13 18:55:37 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c[], int n, int x)
{
	if (c[n - 1] != 48 + x)
		write(1, ", ", 2);
	write(1, &c[0], n);
}

void	a1(char c[], int n, int x)
{
	while (c[x]++ < '9')
	{
		if (x <= n)
		{
			if (n == x + 1)
				print(c, n, x);
			c[x + 1] = c[x];
			a1(c, n, x + 1);
		}
	}
}

void	ft_print_combn(int n)
{
	char	c[9];

	if (n > 0 && n < 10)
	{
		c[0] = 47;
		a1(c, n, 0);
	}
}
/*
int		main(void)
{	
	ft_print_combn(0);
	write(1, "\nCOMBO 1\n", 9);
	ft_print_combn(1);
	write(1, "\nCOMBO 2\n", 9);
	ft_print_combn(2);
	write(1, "\nCOMBO 3\n", 9);
	ft_print_combn(3);
	write(1, "\nCOMBO 4\n", 9);	
	ft_print_combn(4);
	write(1, "\nCOMBO 5\n", 9);
	ft_print_combn(5);
	write(1, "\nCOMBO 6\n", 9);
	ft_print_combn(6);
	write(1, "\nCOMBO 7\n", 9);
	ft_print_combn(7);
	write(1, "\nCOMBO 8\n", 9);
	ft_print_combn(8);
	write(1, "\nCOMBO 9\n", 9);
	ft_print_combn(9);
}
*/
