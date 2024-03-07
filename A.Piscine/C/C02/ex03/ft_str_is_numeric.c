/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:15:01 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/20 17:15:02 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

int	ft_str_is_numeric(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		if (y < '0' || y > '9')
			return (0);
		x++;
	}
	return (1);
}
/*
int	main(void)
{
	char str[] = "13682872";
	int x;
	
	x = ft_str_is_numeric(str);
	printf ("Here => %d", x);
}
*/
