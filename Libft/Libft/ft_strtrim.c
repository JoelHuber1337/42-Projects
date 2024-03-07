/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:06:21 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/19 19:42:59 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getbeg(char const *s1, char const *set)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (set[y])
	{
		if (s1[x] == set[y])
		{
			y = -1;
			x++;
			z = z + 1;
		}
		y++;
	}
	return (z);
}

static int	getend(char const *s1, char const *set)
{
	int	x;
	int	y;
	int	z;

	x = ft_strlen(s1) - 1;
	y = 0;
	z = 0;
	while (set[y])
	{
		if (s1[x] == set[y])
		{
			y = -1;
			x--;
			z = z + 1;
		}
		y++;
	}
	return (z);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	y;
	int	z;
	int	a;

	y = getbeg(s1, set);
	if ((size_t)y == ft_strlen(s1))
		return (ft_strdup(""));
	z = getend(s1, set);
	a = ft_strlen(s1);
	return (ft_substr (s1, y, a - y - z));
}
