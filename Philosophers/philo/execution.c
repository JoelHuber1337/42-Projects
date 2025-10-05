/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:05:13 by johuber           #+#    #+#             */
/*   Updated: 2025/07/28 15:49:14 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*solo(void *input)
{
	t_data	*data;
	long	oldtime;
	long	time;

	data = (t_data *)input;
	oldtime = get_time();
	if (oldtime == -1)
		return (error_msg("gettimeofday failed\n"), NULL);
	pthread_mutex_lock(&data->fork);
	printf("%d	1 has taken a fork\n", 0);
	usleep(data->death * 1000);
	time = get_time();
	if (time == -1)
		return (error_msg("gettimeofday failed\n"), NULL);
	printf("%ld	1 died\n", time - oldtime);
	pthread_mutex_unlock(&data->fork);
	return (NULL);
}

int	solo_leveling(t_data *data)
{
	pthread_t		thread;
	pthread_mutex_t	fork;

	if (pthread_mutex_init(&fork, NULL) != 0)
		return (destroy_data_mutex(data));
	data->fork = fork;
	if (pthread_create(&thread, NULL, &solo, data) != 0)
		return (pthread_mutex_destroy(&data->fork), destroy_data_mutex(data));
	pthread_join(thread, NULL);
	pthread_mutex_destroy(&data->fork);
	destroy_data_mutex(data);
	return (0);
}

int	philo_decay(t_data *data, long size, pthread_t thread)
{
	long	x;

	x = 0;
	pthread_mutex_lock(&data->m_mortis);
	data->mortis = 1;
	pthread_mutex_unlock(&data->m_mortis);
	while (x < size)
	{
		pthread_join(data->threads[x], NULL);
		x++;
	}
	pthread_join(thread, NULL);
	return (1);
}

int	run_philosophers(t_data *data)
{
	pthread_t	thread;
	long		x;
	t_philo		*tmp;

	x = 0;
	tmp = data->philo;
	if (pthread_create(&thread, NULL, &monitoring, data) != 0)
		return (1);
	usleep(2000);
	while (x < data->amount)
	{
		if (pthread_create(&data->threads[x], NULL, &philosophers, tmp) != 0)
			return (philo_decay(data, x, thread));
		x++;
		tmp = tmp->next;
	}
	x = 0;
	while (x < data->amount)
	{
		pthread_join(data->threads[x], NULL);
		x++;
	}
	pthread_join(thread, NULL);
	return (0);
}
