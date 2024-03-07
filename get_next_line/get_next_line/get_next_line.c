/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:52:41 by jhuber            #+#    #+#             */
/*   Updated: 2023/10/31 19:16:38 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*getline(int fd, char *buffer)
{
	char	*temp;
	int		x;

	x = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && x != 0)
	{
		x = read(fd, temp, BUFFER_SIZE);
		if (x == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[x] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*getstr(char *buffer)
{
	char	*str;
	int		x;

	x = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[x] != '\n' && buffer[x])
		x++;
	if (buffer[x] == '\n')
		x++;
	str = malloc(x + 1);
	if (!str)
		return (NULL);
	str[x] = '\0';
	while (--x >= 0)
		str[x] = buffer[x];
	return (str);
}

char	*resetbuff(char *buffer)
{
	char	*temp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (buffer[x] && buffer[x] != '\n')
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (NULL);
	}
	temp = malloc(ft_strlen(buffer) - x + 1);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	x++;
	while (buffer[x])
		temp[y++] = buffer[x++];
	temp[y] = '\0';
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = getline(fd, buffer);
	if (!buffer)
		return (NULL);
	str = getstr(buffer);
	buffer = resetbuff(buffer);
	return (str);
}
