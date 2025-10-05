/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:57:03 by johuber           #+#    #+#             */
/*   Updated: 2025/07/28 18:06:18 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_alarm(t_data *data, long sleep)
{
	long	time;

	time = sleep;
	while (time >= 1000000)
	{
		usleep(1000000);
		time = time - 1000000;
		pthread_mutex_lock(&data->m_mortis);
		if (data->mortis == 1)
		{
			pthread_mutex_unlock(&data->m_mortis);
			return ;
		}
		pthread_mutex_unlock(&data->m_mortis);
	}
	usleep(time);
}

int	taking_second_fork(t_data *data, t_philo *philo, long start)
{
	long	time;

	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left);
	else
		pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&data->m_mortis);
	time = get_time();
	if (!data->mortis && time != -1)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld	%d has taken a fork\n", time - start, philo->id);
		printf("%ld	%d is eating\n", time - start, philo->id);
		pthread_mutex_unlock(&data->print);
	}
	else
	{
		data->mortis = 1;
		pthread_mutex_unlock(&data->m_mortis);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	pthread_mutex_unlock(&data->m_mortis);
	return (0);
}

int	check_time(t_data *data, long time)
{
	if (time == -1)
	{
		pthread_mutex_lock(&data->m_mortis);
		data->mortis = 1;
		pthread_mutex_unlock(&data->m_mortis);
		return (1);
	}
	return (0);
}

void	wait_till_start(t_data *data)
{
	pthread_mutex_lock(&data->p_start);
	pthread_mutex_unlock(&data->p_start);
}

void	jobless_philosophers(t_data *data, t_philo *philo, long start)
{
	long	time;

	time = get_time();
	if (time == -1)
	{
		pthread_mutex_lock(&data->m_mortis);
		data->mortis = 1;
		pthread_mutex_unlock(&data->m_mortis);
		return ;
	}
	if (philo->amount % 2 != 0 && philo->id == philo->amount)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld	%d is thinking\n", time - start, philo->id);
		pthread_mutex_unlock(&data->print);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->print);
		printf("%ld	%d is thinking\n", time - start, philo->id);
		pthread_mutex_unlock(&data->print);
	}
}
