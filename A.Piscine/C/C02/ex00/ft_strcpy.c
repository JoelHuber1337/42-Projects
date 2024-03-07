/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:56:03 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/18 14:56:06 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>
#include <stdio.h>
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char dest[8];
	char src[] = "wdhksoa";
	char *result;
	printf("Before copy => %s", src);
	printf("\n");
	result = ft_strcpy(dest, src);
	printf("After copy => %s", result);
}
*/
