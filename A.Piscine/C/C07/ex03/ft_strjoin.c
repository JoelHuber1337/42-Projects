/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:13:59 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/27 21:14:00 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		str_len(char *str);
char	*str_cpy(char *dest, char *src);
char	*ft_2(char *result, char **strs, char *sep, int size);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*empty_string;
	int		total_len;
	int		i;
	char	*result;
	int		sep_len;

	if (size == 0)
	{
		empty_string = malloc(1);
		empty_string[0] = '\0';
		return (empty_string); 
	}
	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += str_len(strs[i]);
		i++;
	}
	sep_len = str_len(sep) * (size - 1);
	result = malloc(total_len + sep_len + 1);
	result[0] = '\0';
	return (ft_2(result, strs, sep, size));
}

char	*ft_2(char *result, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str_cpy(result + str_len(result), strs[i]);
		if (i < size - 1)
		{
			str_cpy(result + str_len(result), sep);
		}
		i++;
	}
	return (result);
}

char	*str_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
