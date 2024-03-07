/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:02:42 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/25 13:02:43 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strstr(char *str, char *to_find)
{
	int	x;

	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			x = 0;
			while (str[x] == to_find[x] && to_find[x])
				x++;
			if (!to_find[x])
				return (str);
		}
		str++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "Abcdefghijklmnopqrstuvwxyz";
	char	to_find[] = "ghijkl";
	char	*tmp;

	tmp = ft_strstr(str, to_find);
	printf("Found first character to pointer %s", tmp);
}
*/
