/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:23:21 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/25 12:23:23 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	y;

	x = 0;
	while (dest[x])
		x++;
	y = 0;
	while (src[y])
	{
		dest[x + y] = src[y];
		y++;
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

	printf("Original Source => %s\n", src);
	printf("Original Destination => %s\n", dest);

	tmp = ft_strcat(dest, src);

	printf("After the Function call => %s", tmp);
}
*/
