/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:16:05 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/20 19:16:06 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_str_is_printable(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		x++;
		if (y < ' ' || y > '~')
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "ajsf";
	int	tmp;

	tmp = ft_str_is_printable(str);
	printf ("Here => %d", tmp);
}
*/
