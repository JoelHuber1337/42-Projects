/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:51:33 by johuber           #+#    #+#             */
/*   Updated: 2025/07/28 17:53:56 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_thinking(t_data *data, t_philo *philo, long start)
{
	long	time;

	pthread_mutex_lock(&data->m_mortis);
	time = get_time();
	if (!data->mortis && time != -1)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld	%d is thinking\n", time - start, philo->id);
		pthread_mutex_unlock(&data->print);
	}
	else
	{
		data->mortis = 1;
		pthread_mutex_unlock(&data->m_mortis);
		return (1);
	}
	pthread_mutex_unlock(&data->m_mortis);
	if (data->sleep < data->food)
		usleep(data->food - data->sleep);
	usleep(2000);
	return (0);
}

int	go_to_sleep(t_data *data, t_philo *philo, long start)
{
	long	time;

	pthread_mutex_lock(&data->m_mortis);
	pthread_mutex_lock(&data->print);
	time = get_time();
	if (!data->mortis && time != -1)
		printf("%ld	%d is sleeping\n", time - start, philo->id);
	else
	{
		data->mortis = 1;
		pthread_mutex_unlock(&data->print);
		pthread_mutex_unlock(&data->m_mortis);
		return (1);
	}
	pthread_mutex_unlock(&data->print);
	pthread_mutex_unlock(&data->m_mortis);
	if (philo->sleep < 100000)
		usleep(philo->sleep);
	else
		sleep_alarm(data, philo->sleep);
	return (0);
}

int	taking_forks(t_data *data, t_philo *philo, long start, long time)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right);
	else
		pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&data->m_mortis);
	time = get_time();
	if (!data->mortis && time != -1)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld	%d has taken a fork\n", time - start, philo->id);
		pthread_mutex_unlock(&data->print);
	}
	else
	{
		if (philo->id % 2 == 0)
			pthread_mutex_unlock(philo->right);
		else
			pthread_mutex_unlock(philo->left);
		data->mortis = 1;
		return (pthread_mutex_unlock(&data->m_mortis), 1);
	}
	pthread_mutex_unlock(&data->m_mortis);
	if (taking_second_fork(data, philo, start))
		return (1);
	return (0);
}

int	start_eating(t_data *data, t_philo *philo, long start)
{
	long	time;

	if (philo->id % 2 == 0)
		usleep(1200);
	if (taking_forks(data, philo, start, 0))
		return (1);
	time = get_time();
	if (time == -1)
	{
		pthread_mutex_lock(&data->m_mortis);
		data->mortis = 1;
		pthread_mutex_unlock(&data->m_mortis);
		pthread_mutex_unlock(philo->right);
		return (pthread_mutex_unlock(philo->left), 1);
	}
	pthread_mutex_lock(&philo->m_meals);
	philo->meals++;
	philo->m_time = time - start;
	pthread_mutex_unlock(&philo->m_meals);
	if (philo->food < 100000)
		usleep(philo->food);
	else
		sleep_alarm(data, philo->food);
	pthread_mutex_unlock(philo->right);
	return (pthread_mutex_unlock(philo->left), 0);
}

void	*philosophers(void *input)
{
	t_philo	*philo;
	t_data	*data;
	long	start;

	philo = input;
	data = philo->data;
	wait_till_start(data);
	pthread_mutex_lock(&data->m_mortis);
	if (data->mortis == 1)
		return (pthread_mutex_unlock(&data->m_mortis), NULL);
	pthread_mutex_unlock(&data->m_mortis);
	start = get_time();
	if (check_time(data, start))
		return (NULL);
	jobless_philosophers(data, philo, start);
	while (42)
	{
		if (start_eating(data, philo, start))
			break ;
		if (go_to_sleep(data, philo, start))
			break ;
		if (start_thinking(data, philo, start))
			break ;
	}
	return (NULL);
}
