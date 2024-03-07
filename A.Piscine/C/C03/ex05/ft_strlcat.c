/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:12:14 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/25 15:12:15 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	ld;

	x = 0;
	y = 0;
	ld = 0;
	while (dest[ld])
		ld++;
	while (src[y])
		y++;
	while (x < size && src[x] && size > 0)
	{
		dest[x + ld] = src[x];
		x++;
	}
	dest[x + ld] = '\0';
	return (ld + y);
}
/*
int	main(void)
{
	char	src[] = "hijklmnopqrstuvwxyz";
	char	dest[] = "abcdefg";
	unsigned int	tmp;
	unsigned int	size = 20;
	
	tmp = ft_strlcat(dest, src, size);
	printf("Length of the string => %s\n", dest);
	printf("Length of the string(actually) => %d", tmp);
}
*/
