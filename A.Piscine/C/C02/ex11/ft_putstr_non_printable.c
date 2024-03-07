/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:30:13 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/24 19:30:16 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printhex(unsigned char dec)
{
	int	first;
	int	last;

	first = dec / 16;
	last = dec % 16;
	if (first < 10)
		first += '0';
	else
		first += 'a' - 10;
	write(1, &first, 1);
	if (last < 10)
		last += '0';
	else
		last += 'a' - 10;
	write(1, &last, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			printhex(*str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
