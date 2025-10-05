/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:09:51 by johuber           #+#    #+#             */
/*   Updated: 2025/07/28 15:54:05 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_simulation(t_data *data, int error, long time)
{
	long	end;

	end = get_time() - time;
	pthread_mutex_lock(&data->m_mortis);
	data->mortis = 1;
	pthread_mutex_unlock(&data->m_mortis);
	pthread_mutex_lock(&data->print);
	if (end < 0)
		error_msg("gettimeofday failed\n");
	else
		printf("%ld	%d died\n", end, error);
	pthread_mutex_unlock(&data->print);
}

void	limit_reached(t_data *data)
{
	pthread_mutex_lock(&data->m_mortis);
	data->mortis = 1;
	pthread_mutex_unlock(&data->m_mortis);
}

void	*master_key(t_data *data)
{
	data->mortis = 1;
	pthread_mutex_unlock(&data->p_start);
	pthread_mutex_unlock(&data->m_mortis);
	return (NULL);
}
