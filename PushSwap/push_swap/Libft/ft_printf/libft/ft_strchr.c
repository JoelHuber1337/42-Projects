/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:07:36 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/18 19:23:53 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				x;
	unsigned char	y;

	y = (unsigned char)c;
	x = 0;
	while (s[x])
	{
		if (s[x] == y)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == y)
		return ((char *)&s[x]);
	return (0);
}
