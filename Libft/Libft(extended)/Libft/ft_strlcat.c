/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:52:51 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/17 17:04:52 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	x;

	d = ft_strlen(dest);
	x = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (d > size)
		d = size;
	while (src[x] && x + d < size - 1)
	{
		dest[x + d] = src[x];
		x++;
	}
	if (x + d < size)
		dest[x + d] = '\0';
	while (src[x])
		x++;
	return (d + x);
}
