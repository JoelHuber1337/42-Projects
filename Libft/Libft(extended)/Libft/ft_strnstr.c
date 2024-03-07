/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:01:50 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/19 19:18:33 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (little[x] == '\0')
		return ((char *)big);
	while (x < len && big[x])
	{
		y = 0;
		while (big[x + y] == little[y] && x + y < len)
		{
			y++;
			if (little[y] == '\0')
				return ((char *)&big[x]);
		}
		x++;
	}
	return (0);
}
