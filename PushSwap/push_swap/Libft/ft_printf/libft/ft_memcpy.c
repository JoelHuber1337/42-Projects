/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:30:07 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/20 21:52:46 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*srcx;
	unsigned char	*destx;

	srcx = (unsigned char *)src;
	destx = (unsigned char *)dest;
	if (dest == 0 && src == 0)
		return (dest);
	x = 0;
	while (x < n)
	{
		destx[x] = srcx[x];
		x++;
	}
	return (dest);
}
