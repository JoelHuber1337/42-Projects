/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:50:08 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/25 12:50:09 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (dest[y])
		y++;
	while (src[x] && x < nb)
	{
		dest[x + y] = src[x];
		x++;
	}
	dest[x + y] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "hijklmnopqrstuvwxyz";
	char	dest[] = "abcdefg";
	char	*tmp;
	unsigned int		nb = 5;
	
	printf("Original Source => %s\n", src);
	printf("Original Destination => %s\n", dest);
	
	tmp = ft_strncat(dest, src, nb);
	
	printf("After the Function Call => %s", tmp);
}
*/
