/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:35:17 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/20 19:35:19 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

char	*ft_strupcase(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		if (y >= 'a' && y <= 'z')
			str[x] = str[x] - 32;
		x++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "abcABC";
	char	*tmp;

	tmp = ft_strupcase(str);
	printf("After => %s", tmp);
}
*/
