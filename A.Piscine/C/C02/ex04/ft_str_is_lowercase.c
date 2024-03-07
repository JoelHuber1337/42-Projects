/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:50:18 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/20 17:50:19 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

int	ft_str_is_lowercase(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		x++;
		if (y < 'a' || y > 'z')
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char str[] = "AJHFIS";
	int tmp;

	tmp = ft_str_is_lowercase(str);
	printf("Here => %d", tmp);
}
*/
