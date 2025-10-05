/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:05:59 by johuber           #+#    #+#             */
/*   Updated: 2025/07/25 19:01:10 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_free_forks(pthread_mutex_t **forks, long size)
{
	long	x;

	x = 0;
	while (x < size)
	{
		pthread_mutex_destroy(forks[x]);
		free(forks[x]);
		x++;
	}
	free(forks);
	return (1);
}

int	free_philo(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (philo != NULL)
	{
		pthread_mutex_destroy(&philo->m_meals);
		philo = philo->next;
		free(tmp);
		tmp = philo;
	}
	return (1);
}

int	destroy_data_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->m_mortis);
	pthread_mutex_destroy(&data->p_start);
	return (1);
}

int	ft_free_parsing(t_data *data, pthread_mutex_t **forks)
{
	ft_free_forks(forks, data->amount);
	free_philo(data->philo);
	destroy_data_mutex(data);
	return (1);
}

void	ft_free_all(t_data *data)
{
	int	x;

	x = 0;
	ft_free_forks(data->forks, data->amount);
	free_philo(data->philo);
	destroy_data_mutex(data);
	free(data->threads);
}
