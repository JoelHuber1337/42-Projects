/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johuber <johuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:11:04 by johuber           #+#    #+#             */
/*   Updated: 2025/07/25 14:33:47 by johuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int arc, char **arv)
{
	t_data	data;
	int		parsing;

	if ((arc != 5 && arc != 6))
		return (1);
	parsing = wrong_parsing(&data, arc, arv);
	if (parsing == 1)
		return (1);
	if (parsing == 2)
		return (0);
	if (run_philosophers(&data))
	{
		error_msg("Philo threads failed to create\n");
		ft_free_all(&data);
		return (1);
	}
	ft_free_all(&data);
	return (0);
}
