/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:25:18 by jhuber            #+#    #+#             */
/*   Updated: 2023/09/11 15:57:35 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	int		y;

	x = 0;
	while ((s1[x] || s2[x]) && x < n)
	{
		y = (unsigned char)s1[x] - (unsigned char)s2[x];
		x++;
		if (y != 0)
			return (y);
	}
	return (0);
}
