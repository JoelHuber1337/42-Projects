/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:34:41 by johuber           #+#    #+#             */
/*   Updated: 2025/07/27 15:39:30 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	assign_input(t_data *data, long tmp, int x)
{
	if (tmp <= 0)
		return (1);
	if (x == 1)
		data->amount = tmp;
	if (x == 2)
		data->death = tmp;
	if (x == 3)
		data->food = tmp * 1000;
	if (x == 4)
		data->sleep = tmp * 1000;
	if (x == 5)
		data->hunger = tmp;
	return (0);
}

int	check_int(t_data *data, int arc, char **arv)
{
	long	tmp;
	int		x;

	tmp = 0;
	x = 1;
	while (arv[x] && x < arc)
	{
		if (check_char(arv[x]))
			return (destroy_data_mutex(data));
		if (ft_strlen(arv[x]) > 11)
			return (destroy_data_mutex(data));
		tmp = ft_atol(arv[x]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (destroy_data_mutex(data));
		if (assign_input(data, tmp, x))
			return (destroy_data_mutex(data));
		x++;
	}
	return (0);
}

int	make_data(t_data *data)
{
	data->threads = NULL;
	data->amount = -1;
	data->death = -1;
	data->food = -1;
	data->sleep = -1;
	data->hunger = -1;
	data->mortis = 0;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->p_start, NULL) != 0)
		return (pthread_mutex_destroy(&data->print), 1);
	if (pthread_mutex_init(&data->m_mortis, NULL) != 0)
		return (pthread_mutex_destroy(&data->print), \
		pthread_mutex_destroy(&data->p_start), 1);
	data->philo = NULL;
	return (0);
}

int	make_philo(t_data *data)
{
	t_philo			*philo;
	pthread_mutex_t	**forks;
	pthread_t		*threads;
	long			x;

	x = 0;
	while (x < data->amount)
	{
		philo = malloc(sizeof(t_philo));
		if (philo == NULL)
			return (free_philo(data->philo), destroy_data_mutex(data));
		if (assign_philo(data, philo, x))
			return (destroy_data_mutex(data));
		x++;
	}
	forks = init_forks(data->amount);
	if (forks == NULL)
		return (free_philo(data->philo), destroy_data_mutex(data));
	assign_forks(data, forks);
	threads = malloc(sizeof(pthread_t) * data->amount);
	if (!threads)
		return (ft_free_parsing(data, forks));
	data->threads = threads;
	data->forks = forks;
	return (0);
}

int	wrong_parsing(t_data *data, int arc, char **arv)
{
	if (make_data(data))
		return (error_msg("Failed to create data Mutexes\n"));
	if (check_int(data, arc, arv))
		return (error_msg("Invalid input\n"));
	if (data->amount == 1)
	{
		if (solo_leveling(data) == 1)
			return (error_msg("Failed to execute Philosophers\n"));
		return (2);
	}
	if (make_philo(data))
		return (error_msg("Failed to create philo Struct\n"));
	return (0);
}
