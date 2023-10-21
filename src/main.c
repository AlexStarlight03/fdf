/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/20 22:42:57 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	map_color(t_point **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (!map[i][j].last)
		{
			if (map[i][j].color != -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_width(t_point **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (!map[y][x].last)
		x++;
	while (map[y])
		y++;
	return (y + x);
}

void	init_start(t_info *info, t_point **map)
{
	info->matrix = map;
	info->map_width = map_width(map);
	info->z_scale = 1;
	info->scale = 50;
	info->angle = 0.523599;
	info->random_color = 0;
	info->window_x = 2000;
	info->window_y = 1000;
	info->color_style = 1;
	info->is_iso = 1;
	info->shift_x = info->window_x / 3;
	info->shift_y = info->window_x / 3;
	info->has_colors = map_color(map);
	info->mlx = mlx_init();
	if (!info->mlx)
		err_exit(info, "Mlx error");
	info->window = mlx_new_window(info->mlx, \
									info->window_x, info->window_y, "Fdf");
	if (!info->window)
		err_exit(info, "Mlx error");
}

int	main(int argc, char **argv)
{
	t_point	**map;
	t_info	*info;

	if (argc != 2)
		err_exit(0, "You need exactly 2 arguments!");
	map = get_map(argv[1]);
	info = (t_info *)malloc(sizeof(t_info) * 1);
	if (!info)
		err_exit(0, "Error malloc");
	init_start(info, map);
	info->img.img = mlx_new_image(info->mlx, info->window_x, info->window_y);
	info->img.addr = mlx_get_data_addr(info->img.img, \
		&info->img.bits_per_pixel, &info->img.line_length, &info->img.endian);
	breseham(map, info);
	mlx_key_hook(info->window, key_info, info);
	mlx_hook(info->window, 17, 0, exit_window, info);
	mlx_loop(info->mlx);
}
