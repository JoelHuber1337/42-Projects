/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:32:14 by johuber           #+#    #+#             */
/*   Updated: 2025/07/23 14:05:57 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*get_last_node(t_philo *philo)
{
	if (!philo)
		return (philo);
	while (philo->next)
		philo = philo->next;
	return (philo);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (0);
	while (str[x])
		x++;
	return (x);
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		x;

	res = 0;
	sign = 1;
	x = 0;
	while (str[x] == ' ' || str[x] == '\t' || str[x] == '\n'
		|| str[x] == '\v' || str[x] == '\f' || str[x] == '\r')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + (str[x] - '0');
		x++;
	}
	return (res * sign);
}

int	check_char(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (!(str[x >= '0' && str[x] <= '9']))
			return (1);
		x++;
	}
	return (0);
}
