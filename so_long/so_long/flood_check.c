/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:16:16 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 20:15:17 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libft/libft.h"

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= (data->x / 32 - 1) || y < 0
		|| y >= (data->y / 32 - 1) || data->map2[y][x] == '1')
		return ;
	data->map2[y][x] = '1';
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
	flood_fill(data, x + 1, y);
}

void	check_ppos(t_data *data, char **str, int y, int x)
{
	int	z;

	z = 0;
	if (str[y][x + 1] == '1' || str[y][x + 1] == 'E')
		z++;
	if (str[y][x - 1] == '1' || str[y][x - 1] == 'E')
		z++;
	if (str[y + 1][x] == '1' || str[y + 1][x] == 'E')
		z++;
	if (str[y - 1][x] == '1' || str[y - 1][x] == 'E')
		z++;
	if (z == 4)
		errorone(data, "Player surrounded by Walls and possibly the Exit.\n");
}

void	get_ppos(t_data *data, char **str)
{
	int	y;
	int	x;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == 'P')
			{
				data->ppos_x = x;
				data->ppos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	get_ppos(data, data->map);
	check_ppos(data, data->map, data->ppos_y, data->ppos_x);
	flood_fill(data, data->ppos_x, data->ppos_y);
	if (check_specials(data, data->map2, 'C'))
		errorone(data, "Invalid Path on Map.\n");
	if (check_specials(data, data->map2, 'P'))
		errorone(data, "Invalid Path on Map.\n");
	if (check_specials(data, data->map2, 'E'))
		errorone(data, "Invalid Path on Map.\n");
}
