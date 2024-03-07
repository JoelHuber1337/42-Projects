/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:39:01 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 22:54:30 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libft/libft.h"

void	check_borders(t_data *data, char **str)
{
	int	x;
	int	y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (y == 0 && str[y][x] != '1')
				errorone(data, "The top of the Map does not have Walls.\n");
			if (x == 0 && str[y][x] != '1')
				errorone(data, "Left side of the Map does not have Walls.\n");
			if (y == (data->y / 32 - 1) && str[y][x] != '1')
				errorone(data, "The bottom of the Map does not have Walls.\n");
			if (x == (data->x / 32 - 2) && str[y][x] != '1')
				errorone(data, "Right side of the Map does not have Walls.\n");
			x++;
		}
		y++;
	}
}

int	check_specials(t_data *data, char **str, char c)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == c)
				count++;
			if (str[y][x] != '0' && str[y][x] != '1' && str[y][x] != 'C'
				&& str[y][x] != 'E' && str[y][x] != 'P')
				errorone(data, "Invalid Blocks in the Map.\n");
			x++;
		}
		y++;
	}
	return (count);
}

void	check_blocks(t_data *data)
{
	if (check_specials(data, data->map, 'P') != 1)
		errorone(data, "Player position is not one.\n");
	if (check_specials(data, data->map, 'E') != 1)
		errorone(data, "Exit position is not one.\n");
	data->collect = check_specials(data, data->map, 'C');
	if (data->collect < 1)
		errorone(data, "No Collectables on the Map.\n");
	check_borders(data, data->map);
	check_path(data);
}

void	convert_map(t_data *data, char *str)
{
	int		fd;
	int		i;
	int		size;
	char	buffer[2];

	i = 0;
	size = 1;
	buffer[1] = '\0';
	fd = open(str, O_RDONLY);
	while (size == 1)
	{
		size = read(fd, buffer, 1);
		if (size != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map[i] = ft_strjoin(data->map[i], buffer);
			data->map2[i] = ft_strjoin(data->map2[i], buffer);
		}
		else
			i++;
	}
	close(fd);
	check_blocks(data);
}
