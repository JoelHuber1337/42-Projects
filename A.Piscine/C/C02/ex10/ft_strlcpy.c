/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:27:57 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/22 20:27:59 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (x < size - 1 && src[x] && size > 0)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	x = 0;
	while (src[x])
	{
		x++;
		y++;
	}
	return (y);
}
/*
int	main(void)
{
	char	src[] = "waishfkas";
	char	dest[9];
	unsigned int	tmp;
	unsigned int	size = 20;
	
	tmp = ft_strlcpy(dest, src, size);
	printf("Length of the string => %s", dest);
}
*/
