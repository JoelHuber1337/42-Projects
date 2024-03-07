/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:13:02 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 21:13:03 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strdup(char *src)
{
	char	*x;
	int		i;
	int		length;

	length = ft_strlen(src);
	x = (char *)malloc((length + 1) * sizeof(char));
	if (x == NULL)
		return (0);
	i = 0;
	while (i < length)
	{
		x[i] = src[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
