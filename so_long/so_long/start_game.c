/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:28:42 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 23:04:02 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, void *img, int x, int y)
{
	int	z;

	z = mlx_put_image_to_window(data->mlx, data->win, img, (x * 32), (y * 32));
	if (z == 1)
	{
		errorone(data, "Image to Window failed!");
	}
}

void	get_map2(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P')
		put_image(data, data->img->player, x, y);
	if (data->map[y][x] == '1')
		put_image(data, data->img->walls, x, y);
	if (data->map[y][x] == '0')
		put_image(data, data->img->empty_tiles, x, y);
	if (data->map[y][x] == 'E' && data->collect == 0)
		put_image(data, data->img->exit_open, x, y);
	else if (data->map[y][x] == 'E')
		put_image(data, data->img->exit_closed, x, y);
	if (data->map[y][x] == 'C')
		put_image(data, data->img->coll_id, x, y);
}

int	get_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			get_map2(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	start_game(t_data *data)
{
	int	x;
	int	a;

	a = 0;
	x = 0;
	while (data->map[x])
		x++;
	if (x != (data->y / 32))
		a = 32;
	data->win = mlx_new_window(data->mlx,
			(data->x - 32), (data->y - a), "so_long");
	if (data->win == NULL)
		errorone(data, "Window initiation failed.\n");
	mlx_hook(data->win, 2, (1L << 0), get_keyboard, data);
	mlx_hook(data->win, 17, 0, exit_mouse, data);
	mlx_loop_hook(data->mlx, &get_map, data);
	mlx_loop(data->mlx);
	mlx_do_sync(data->mlx);
}
