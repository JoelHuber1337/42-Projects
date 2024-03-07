/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:32:45 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/24 22:05:09 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		y;
	int		z;

	y = ft_strlen(s1);
	z = ft_strlen(s2);
	str = malloc(y + z + 1);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, y + 1);
	ft_strlcat(str, s2, z + y + 1);
	free(s1);
	return (str);
}
