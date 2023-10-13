/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breseham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:23:49 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 13:06:24 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	check_neg(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	img_max(float x, float y)
{
	if (x >= y)
		return (x);
	return (y);
}

void	draw_line(t_point a, t_point b, t_point *map)
{
	float	curr_x;
	float	curr_y;
	float	max;
	int		color;

	params(&a, &b, map);
	curr_x = b.x - a.x;
	curr_y = b.y - a.y;
	max = img_max(check_neg(curr_x), check_neg(curr_y));
	curr_x /= max;
	curr_y /= max;
	color = find_color(map, a, b);
	while((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_put_pixel((mlx_image_t *)map->a.x, a.y, color);
		a.x += curr_x;
		a.y += curr_y;
		if (a.x > map->win_x || a.y > map->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_start(t_point *map)
{
	int		x;
	int		y;
	
	y = 0;
	while(map->matrix[y])
	{
		x = 0;
		while (1)
		{
			if(map->matrix[y + 1])
				draw_line(map->matrix[y][x], map->matrix[y + 1][x], map);
			if(!map->matrix[y][x].last)
				draw_line(map->matrix[y][x], map->matrix[y][x + 1], map);
			if(map->matrix[y][x].last)
				break ;
			x++;	
		}
		y++;
	}
	img_in_window(map);
}