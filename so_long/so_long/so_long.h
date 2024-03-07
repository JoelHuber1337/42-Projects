/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:08:22 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/25 22:09:54 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "Libft/libft.h"
# include <stdio.h>
# define PATH_P "./textures/Character.xpm"
# define PATH_C "./textures/Collectable_ID.xpm"
# define PATH_W "./textures/Walls.xpm"
# define PATH_ET "./textures/Empty_tiles.xpm"
# define PATH_EC "./textures/exit_closed.xpm"
# define PATH_EO "./textures/exit_open.xpm"

typedef struct s_img
{
	void	*player;
	void	*exit_closed;
	void	*exit_open;
	void	*walls;
	void	*empty_tiles;
	void	*coll_id;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*addr;
	char	**map;
	char	**map2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		screen_x;
	int		screen_y;
	int		x;
	int		y;
	int		collect;
	int		ppos_x;
	int		ppos_y;
	int		moves;
	t_img	*img;
}				t_data;

void	prep_alloc(t_data *data);
void	check_map(char *str, t_data *data);
int		errorone(t_data *data, char *str);
void	free_all(t_data *data);
void	img_free(t_data *data);
void	free_map(char **str);
int		maplen(t_data *data, int fd);
int		mapwidth(t_data *data, int fd, int x);
int		check_win(t_data *data);
void	convert_map(t_data *data, char *str);
void	check_blocks(t_data *data);
int		check_specials(t_data *data, char **str, char c);
void	check_borders(t_data *data, char **str);
void	check_path(t_data *data);
void	get_ppos(t_data *data, char **str);
void	check_ppos(t_data *data, char **str, int y, int x);
void	flood_fill(t_data *data, int x, int y);
void	get_textures(t_data *data);
void	prep_images(t_data *data);
void	*get_image(t_data *data, char *path, void *img);
void	start_game(t_data *data);
int		get_keyboard(int key, t_data *data);
int		exit_esc(int key, t_data *data);
void	game_won(t_data *data, char *str);
int		exit_mouse(t_data *data);
int		get_map(t_data *data);
void	get_map2(t_data *data, int x, int y);
void	put_image(t_data *data, void *img, int x, int y);

#endif
