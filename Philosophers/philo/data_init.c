/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:47:20 by johuber           #+#    #+#             */
/*   Updated: 2025/07/27 15:38:55 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assign_forks(t_data *data, pthread_mutex_t **forks)
{
	t_philo	*tmp;
	int		x;

	x = 0;
	tmp = data->philo;
	while (tmp->next)
	{
		tmp->left = forks[x];
		x++;
		tmp = tmp->next;
	}
	tmp->left = forks[x];
	tmp->right = forks[x - 1];
	tmp = data->philo;
	tmp->right = forks[x];
	x = 0;
	tmp = tmp->next;
	while (tmp->next)
	{
		tmp->right = forks[x];
		x++;
		tmp = tmp->next;
	}
}

pthread_mutex_t	**free_forks(pthread_mutex_t **tmp, \
long size, int flag, long amount)
{
	long	x;

	x = 0;
	if (flag)
	{
		while (x < size)
			pthread_mutex_destroy(tmp[x++]);
		x = 0;
		while (x < amount)
		{
			free(tmp[x]);
			x++;
		}
	}
	else
	{
		while (x < size)
		{
			free(tmp[x]);
			x++;
		}
	}
	free(tmp);
	return (NULL);
}

pthread_mutex_t	**init_forks(long amount)
{
	pthread_mutex_t		**tmp;
	long				x;

	x = 0;
	tmp = malloc(sizeof(pthread_mutex_t *) * amount);
	if (!tmp)
		return (NULL);
	while (x < amount)
	{
		tmp[x] = malloc(sizeof(pthread_mutex_t));
		if (!tmp[x])
			return (free_forks(tmp, x, 0, amount));
		x++;
	}
	x = 0;
	while (x < amount)
	{
		if (pthread_mutex_init(tmp[x], NULL) != 0)
			return (free_forks(tmp, x, 1, amount));
		x++;
	}
	return (tmp);
}

int	assign_philo(t_data *data, t_philo *philo, int x)
{
	philo->id = x + 1;
	philo->meals = 0;
	philo->amount = data->amount;
	philo->death = data->death;
	philo->food = data->food;
	philo->m_time = 0;
	philo->sleep = data->sleep;
	philo->data = data;
	philo->next = NULL;
	if (pthread_mutex_init(&philo->m_meals, NULL) != 0)
	{
		free(philo);
		if (data->philo == NULL)
			return (1);
		return (free_philo(data->philo));
	}
	if (!data->philo)
		data->philo = philo;
	else
		get_last_node(data->philo)->next = philo;
	return (0);
}
