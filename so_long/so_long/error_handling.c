/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:52:35 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 20:54:22 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libft/libft.h"

void	free_map(char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		free(str[x]);
		x++;
	}
	free(str);
}

void	img_free(t_data *data)
{
	if (data->img->walls != NULL)
		mlx_destroy_image(data->mlx, data->img->walls);
	if (data->img->player != NULL)
		mlx_destroy_image(data->mlx, data->img->player);
	if (data->img->coll_id != NULL)
		mlx_destroy_image(data->mlx, data->img->coll_id);
	if (data->img->exit_closed != NULL)
		mlx_destroy_image(data->mlx, data->img->exit_closed);
	if (data->img->exit_open != NULL)
		mlx_destroy_image(data->mlx, data->img->exit_open);
	if (data->img->empty_tiles != NULL)
		mlx_destroy_image(data->mlx, data->img->empty_tiles);
	free(data->img);
	return ;
}

void	free_all(t_data *data)
{
	if (data->map != NULL)
		free_map(data->map);
	if (data->map2 != NULL)
		free_map(data->map2);
	if (data->img != NULL)
		img_free(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	errorone(t_data *data, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	free_all(data);
	exit (0);
}
