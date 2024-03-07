/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:46:52 by jhuber            #+#    #+#             */
/*   Updated: 2023/07/26 16:46:54 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	x;

	result = 0;
	sign = 1;
	x = 0;
	while (str[x] == ' ' || str[x] == '\t' || str[x] == '\n'
		|| str[x] == '\v' || str[x] == '\f' || str[x] == '\r') 
		x++;
	while (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + (str[x] - '0');
		x++;
	}
	return (result * sign);
}
/*---
int	main(void)
{
	printf("%d\n", ft_atoi("---+--+1234ab567") );
	return 0;
}
*/
