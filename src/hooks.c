/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:08:48 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 11:00:11 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_colors_hook(t_point *map, keys_t key)
{
	if (key == MLX_KEY_SPACE)
		map->color = standard;
	else if (key == MLX_KEY_1)
		map->color = earth;
	else if (key == MLX_KEY_2)
		map->color = fire;
	else if (key == MLX_KEY_3)
		map->color = rainbow;
	else if (key == MLX_KEY_4)
		map->color = pastel;
	draw_start(map);
}


void	ft_projection_hook(t_point *map, keys_t key)
{
	if (key == MLX_KEY_I || key == MLX_KEY_SPACE)
		map->cam->proj = iso;
	else if (key == MLX_KEY_T)
		map->cam->proj= top_view;
	draw_start(map);
}

void	ft_key_hooks(mlx_key_data_t keydata, void *param)
{
	t_point *map;

	map = (t_point *)param;
	if (mlx_is_key_down(map->mlx_ptr, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_Q))
		clean_exit(map, NULL);
	if (mlx_is_key_down(map->mlx_ptr, MLX_KEY_I)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_SPACE)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_T))
		ft_projection_hook(map, keydata.key);
	if (mlx_is_key_down(map->mlx_ptr, MLX_KEY_1)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_2)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_3)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_4)
		|| mlx_is_key_down(map->mlx_ptr, MLX_KEY_SPACE))
		ft_colors_hook(map, keydata.key);
	
}