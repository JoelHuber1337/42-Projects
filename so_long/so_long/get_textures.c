/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:54:25 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 21:44:04 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_image(t_data *data, char *path, void *img)
{
	int	iw;
	int	ih;

	img = mlx_xpm_file_to_image(data->mlx, path, &iw, &ih);
	if (!img)
		errorone(data, "Failed to access XPM file.\n");
	return (img);
}

void	get_textures(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		errorone(data, "Image Structure failed to Malloc\n");
	data->img = img;
	prep_images(data);
	img->empty_tiles = get_image(data, PATH_ET, img->empty_tiles);
	img->walls = get_image(data, PATH_W, img->walls);
	img->player = get_image(data, PATH_P, img->player);
	img->coll_id = get_image(data, PATH_C, img->coll_id);
	img->exit_closed = get_image(data, PATH_EC, img->exit_closed);
	img->exit_open = get_image(data, PATH_EO, img->exit_open);
	data->moves = 0;
}
