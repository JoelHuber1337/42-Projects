/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:47:00 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 22:10:32 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "Libft/libft.h"

int	main(int arv, char **arc)
{
	t_data	data;

	if (arv == 2)
	{
		prep_alloc(&data);
		check_map(arc[1], &data);
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			errorone(&data, "MLX inition Error\n");
		check_win(&data);
		data.map = ft_calloc(data.y + 1, sizeof(char));
		if (data.map == NULL)
			errorone(&data, "Map allocation failed\n");
		data.map2 = ft_calloc(data.y + 1, sizeof(char));
		if (data.map2 == NULL)
			errorone(&data, "Map copy allocation failed\n");
		convert_map(&data, arc[1]);
		get_textures(&data);
		start_game(&data);
	}
	return (0);
}
