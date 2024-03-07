/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:38:07 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/19 16:38:09 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	x;

	x = 0;
	while ((unsigned int)x < n && src[x] != 0)
	{
		dest[x] = src[x];
		x++;
	}
	while ((unsigned int)x < n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}
/*
int	main(void)
{
	int n;
	n = 14;
	char dest[10];
	char src[] = "wdhksoa";
	char *result;
	printf("Before copy => %s", src);
	printf("\n");
	result = ft_strncpy(dest, src, n);
	printf("After copy => %s", result);
}
*/
