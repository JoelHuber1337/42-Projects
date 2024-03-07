/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:55:07 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/28 14:47:59 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libft/libft.h"

int	check_win(t_data *data)
{
	mlx_get_screen_size(data->mlx, &data->screen_x, &data->screen_y);
	if (data->x > data->screen_x || data->y > (data->screen_y - 128))
		errorone(data, "Map is too big\n");
	return (1);
}

int	maplen(t_data *data, int fd)
{
	int		size;
	char	buffer[2];

	size = 0;
	buffer[0] = '1';
	buffer[1] = '\0';
	while (buffer[0] == '1')
	{
		size += read(fd, buffer, 1);
		if (size == -1)
			errorone(data, "Read function failed\n");
		if (size == 0)
			errorone(data, "Map file is Empty.\n");
	}
	if (buffer[0] != '\n')
		errorone(data, "The Top Wall of the Map is incorrect\n");
	if (size < 3)
		errorone(data, "The Top Wall of the Map is not the correct size\n");
	return (size);
}

int	mapwidth(t_data *data, int fd, int x)
{
	int		size;
	int		length;
	char	buffer[2];

	length = -1;
	size = 2;
	buffer[0] = '0';
	buffer[1] = '\0';
	while (read(fd, buffer, 1))
	{
		length++;
		if (buffer[0] == '\n')
		{
			size++;
			if (length == (x / 32 - 1))
				length = -1;
			else
				errorone(data, "Map is not rectangular.\n");
		}
	}
	if (buffer[0] == '\0')
	{
		if (length == (x / 32 - 1))
			length = -1;
		else
			errorone(data, "Map is not rectangular.\n");
	}
	return (size);
}

void	check_map(char *str, t_data *data)
{
	int		fd;

	if (ft_strlen(str) < 5)
		errorone(data, "The name of the Map file is not Correct.\n");
	if (ft_strnstr(str, ".ber", ft_strlen(str)) == NULL)
		errorone(data, "Map is not a ber file\n");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		errorone(data, "Open failed, check if the Map path is valid\n");
	data->x = (maplen(data, fd) * 32);
	data->y = (mapwidth(data, fd, data->x) * 32);
	close(fd);
}
