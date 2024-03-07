/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:15:22 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 21:43:48 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_esc(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}

void	game_won(t_data *data, char *str)
{
	write(2, str, ft_strlen(str));
	free_all(data);
	exit(0);
}

int	exit_mouse(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

void	prep_alloc(t_data *data)
{
	data->img = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->map = NULL;
	data->map2 = NULL;
}

void	prep_images(t_data *data)
{
	data->img->empty_tiles = NULL;
	data->img->walls = NULL;
	data->img->player = NULL;
	data->img->coll_id = NULL;
	data->img->exit_closed = NULL;
	data->img->exit_open = NULL;
}
