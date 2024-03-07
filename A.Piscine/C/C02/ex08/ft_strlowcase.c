/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:48:47 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/22 19:48:49 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

char	*ft_strlowcase(char *str)
{
	int		x;
	char	y;

	x = 0;
	while (str[x])
	{
		y = str[x];
		if (y >= 'A' && y <= 'Z')
			str[x] = str[x] + 32;
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
