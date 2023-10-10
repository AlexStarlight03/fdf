/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/10 11:58:45 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	
}

t_point	*ft_init_map(void)
{
	static t_point *map;

	if (!map)
	{
		map = ft_calloc(sizeof(t_point), 1);
		map->x = 0;
		map->y = 0;
		map->z = INT_MIN;
		map->height = 0;
		map->width = 0;
		map->matrix = 0;
		map->cam = ft_init_camera();
		map->algo = ft_init_dda();
		map->pos= ft_calloc(sizeof(t_line), 1);
		map->menu = ft_calloc(sizeof(t_menu), 1);
		
	}
}

bool ft_init(t_point *map, char *file)
{
	map->mlx_ptr = mlx_init(WIDTH, HEIGHT, file, true);
	map->img->ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx_ptr, map->img_ptr, 300, 0);
	if (!map->mlx_ptr || !map->img_ptr
		|| (mlx_image_to_window(map->mlx_ptr, map->img_ptr, 300, 0) == 0))
			clean_exit(map, KRED"MLX has failes\n"KNRM);
	return (true);
}


int	main(int argc, char **argv)
{
	t_point *map;

	if (argc != 2)
	{	
		ft_putstr_fd("Please have 2 arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	map = ft_init_map();
	get_map(map, argv[1]);
	read_map(map, argv[1]);
	if (ft_init(map, argv[1]) == true)
	{
		mlx_key_hook(map->mlx_ptr, &ft_key_hooks, map);
		draw_start(map);
		mlx_loop(map->mlx_ptr);
	}
	clean_exit(map, NULL);
}