/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:42:23 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/24 21:42:25 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	y;
	int	x;

	x = 0;
	while ((s1[x] || s2[x]) && (unsigned int) x < n)
	{
		y = s1[x] - s2[x];
		x++;
		if (y != 0)
			return (y);
	}
	return (0); 
}
/*
int	main(void)
{
	char	s1[] = "afiojhgpod";
	char	s2[] = "afiojhgpod";
	int	tmp;
	unsigned int	n = 5;
	
	tmp = ft_strncmp(s1, s2, n);
	printf("Returned value => %d", tmp);
}
*/
