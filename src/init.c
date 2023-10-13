/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:22:02 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 10:09:01 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_cam	*ft_init_cam(void)
{
	static	t_cam *cam;
	
	if (!cam)
	{
		cam = ft_calloc(sizeof(t_cam), 1);
		cam->proj = iso;
	}
	return (cam);
}

t_algo	*ft_init_algo(void)
{
	static t_algo	*algo;

	if (!algo)
	{
		algo = ft_calloc(sizeof(t_algo), 1);
		algo->x = 0;
		algo->y = 0;
		algo->delta_x = 0;
		algo->delta_y = 0;
		algo->ptp = 0;
		algo->delta_max = 0;
		algo->pixel = 0;
	}
	return (algo);
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
		map->cam = ft_init_cam();
		map->algo = ft_init_algo();
		map->pos= ft_calloc(sizeof(t_line), 1);
		map->menu = ft_calloc(sizeof(t_menu), 1);
		map->shift_x = 0;
		map->shift_y = 0;
		map->color = standard;
		map->scale = 0;
	}
	return (map);
}