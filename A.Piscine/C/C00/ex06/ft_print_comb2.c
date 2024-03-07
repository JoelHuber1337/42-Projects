/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:09:16 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/13 05:09:31 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_n(int ij, int *comma, int *end)
{
	char	digit1;
	char	digit2;

	digit1 = ij / 10 + '0';
	write(1, &digit1, 1);
	digit2 = ij % 10 + '0';
	write(1, &digit2, 1);
	(*end)++;
	if (*end == 9900)
	{
	}
	else if (*comma % 2 == 1)
	{
		write(1, ", ", 2);
		(*comma)++;
	}
	else
	{
		write(1, " ", 1);
		(*comma)++;
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	comma;
	int	end;

	comma = 0;
	end = 0;
	i = 0;
	j = 0;
	while (j <= 98)
	{
		i = j + 1;
		while (i <= 99)
		{
			write_n(j, &comma, &end);
			write_n(i, &comma, &end);
			i++;
		}
		j++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
}
*/
