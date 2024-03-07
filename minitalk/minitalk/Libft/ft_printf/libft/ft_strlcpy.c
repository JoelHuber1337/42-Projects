/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:52:55 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/16 19:28:31 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	while (x < size - 1 && src[x] && size > 0)
	{
		dest[x] = src[x];
		x++;
	}
	if (size > 0)
		dest[x] = '\0';
	x = 0;
	while (src[x])
		x++;
	return (x);
}
