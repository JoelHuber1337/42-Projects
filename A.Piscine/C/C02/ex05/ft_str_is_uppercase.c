/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:05:00 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/20 19:05:01 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

int	ft_str_is_uppercase(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		x++;
		if (y < 'A' || y > 'Z')
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "uahfhsh29739/";
	int	tmp;

	tmp = ft_str_is_uppercase(str);
	printf("Here => %d", tmp);
}
*/
