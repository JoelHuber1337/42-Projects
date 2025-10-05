/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:18:58 by johuber           #+#    #+#             */
/*   Updated: 2025/09/17 19:46:09 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	times;
	long			time;

	if (gettimeofday(&times, NULL) == -1)
		return (-1);
	time = (times.tv_sec * 1000) + (times.tv_usec / 1000);
	return (time);
}

int	check_philos(t_data *data, t_philo *o_philo, long start)
{
	long	time;
	t_philo	*philo;
	long	hunger;

	hunger = 0;
	philo = o_philo;
	time = get_time() - start;
	if (time < 0)
		return (error_msg("gettimeofday failed\n"), -1);
	while (philo != NULL)
	{
		pthread_mutex_lock(&philo->m_meals);
		if (data->death <= (time - philo->m_time))
		{
			pthread_mutex_unlock(&philo->m_meals);
			return (philo->id);
		}
		if (philo->meals >= data->hunger && data->hunger != -1)
			hunger++;
		pthread_mutex_unlock(&philo->m_meals);
		philo = philo->next;
	}
	if (hunger == data->amount)
		return (-1);
	return (0);
}

int	check_philos_prep(t_data *data, t_philo *philo, long time)
{
	int	exit;

	exit = check_philos(data, philo, time);
	if (exit > 0)
	{
		end_simulation(data, exit, time);
		return (1);
	}
	if (exit == -1)
	{
		limit_reached(data);
		return (1);
	}
	pthread_mutex_lock(&data->m_mortis);
	if (data->mortis == 1)
	{
		pthread_mutex_lock(&data->print);
		error_msg("gettimeofday failed\n");
		pthread_mutex_unlock(&data->print);
		pthread_mutex_unlock(&data->m_mortis);
		return (1);
	}
	pthread_mutex_unlock(&data->m_mortis);
	return (0);
}

void	*monitoring(void *input)
{
	t_data	*data;
	t_philo	*philo;
	long	time;

	data = (t_data *)input;
	philo = data->philo;
	pthread_mutex_lock(&data->p_start);
	usleep(200000 * (data->amount / 10));
	pthread_mutex_lock(&data->m_mortis);
	if (data->mortis == 1)
		return (master_key(data));
	pthread_mutex_unlock(&data->m_mortis);
	time = get_time();
	pthread_mutex_unlock(&data->p_start);
	if (time == -1)
		return (limit_reached(data), NULL);
	while (42)
	{
		if (check_philos_prep(data, data->philo, time))
			break ;
		usleep(100);
	}
	usleep(1000);
	return (NULL);
}
