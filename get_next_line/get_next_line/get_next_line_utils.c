/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:52:36 by jhuber            #+#    #+#             */
/*   Updated: 2023/11/01 17:14:03 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (free(s1), NULL);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2)+1);
	if (!str)
		return (free(s1), NULL);
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
		str[x++] = s2[y++];
	str[x] = '\0';
	return (free(s1), str);
}

char	*ft_strchr(const char *s, int c)
{
	int				x;
	unsigned char	y;

	y = (unsigned char)c;
	x = 0;
	if (!s)
		return (NULL);
	while (s[x])
	{
		if (s[x] == y)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == y)
		return ((char *)&s[x]);
	return (0);
}
