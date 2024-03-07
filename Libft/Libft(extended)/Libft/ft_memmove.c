/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:55:37 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/20 22:04:31 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		x;

	if (dest == 0 && src == 0)
		return (dest);
	if (dest > src && src + n > dest)
	{
		x = n - 1;
		while (x >= 0)
		{
			*(unsigned char *)(dest + x) = *(unsigned char *)(src + x);
			x--;
		}
		return (dest);
	}
	else
	{
		x = 0;
		while ((size_t)x < n)
		{
			*(unsigned char *)(dest + x) = *(unsigned char *)(src + x);
			x++;
		}
		return (dest);
	}
	return (dest);
}
