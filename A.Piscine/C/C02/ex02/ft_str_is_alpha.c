/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:36:13 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/20 16:37:59 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_str_is_alpha(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		x++;
		if ((y < 'A' || y > 'Z') && (y < 'a' || y > 'z'))
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char str[] = "sihf\\";
	int tmp;

	tmp = ft_str_is_alpha(str);
	printf("Here => %d", tmp);
}
*/
