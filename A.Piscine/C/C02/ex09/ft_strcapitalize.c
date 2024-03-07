/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:52:03 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/22 19:52:05 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

char	*ft_strcapitalize(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] >= 'a' && str[x] <= 'z' && x == 0)
			str[x] = str[x] - 32;
		else if (!((str[x - 1] >= 'a' && str[x - 1] <= 'z')
				|| (str[x - 1] >= 'A' && str[x - 1] <= 'Z')
				|| (str[x - 1] >= '0' && str[x - 1] <= '9')))
		{
			if (str[x] >= 'a' && str[x] <= 'z')
				str[x] = str[x] -32;
		}
		x++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	*tmp;

	tmp = ft_strcapitalize(str);
	printf("After => %s", tmp);
}
*/
