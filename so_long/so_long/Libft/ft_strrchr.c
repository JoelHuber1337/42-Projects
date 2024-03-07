/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:13:45 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/18 19:24:44 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				x;
	unsigned char	y;

	y = (unsigned char)c;
	x = ft_strlen(s);
	if (s[x] == y)
		return ((char *)&s[x]);
	while (x >= 0)
	{
		if (s[x] == y)
			return ((char *)&s[x]);
		x--;
	}
	return (0);
}
