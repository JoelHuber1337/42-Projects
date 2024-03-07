/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:08:55 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 21:49:53 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_data *data, int new_y, int new_x)
{
	int	x;
	int	y;

	get_ppos(data, data->map);
	x = data->ppos_x + new_x;
	y = data->ppos_y + new_y;
	if (data->map[y][x] == '0' || data->map[y][x] == 'C')
	{
		data->map[data->ppos_y][data->ppos_x] = '0';
		data->ppos_x = x;
		data->ppos_y = y;
		if (data->map[y][x] == 'C')
			data->collect--;
		data->map[y][x] = 'P';
		data->moves++;
		ft_printf("Move count : %d\n", data->moves);
	}
	if (data->map[y][x] == 'E' && data->collect == 0)
		game_won(data, "Level Completed!\n");
}

int	get_keyboard(int key, t_data *data)
{
	exit_esc(key, data);
	if (key == XK_w)
		player_move(data, -1, 0);
	if (key == XK_a)
		player_move(data, 0, -1);
	if (key == XK_s)
		player_move(data, +1, 0);
	if (key == XK_d)
		player_move(data, 0, +1);
	return (0);
}
