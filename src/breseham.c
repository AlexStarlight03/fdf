/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breseham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:23:49 by adube             #+#    #+#             */
/*   Updated: 2023/10/06 10:41:39 by adube            ###   ########.fr       */
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

void	draw_line(t_point a, t_point b, t_point *param)
{
	float	x;
	float	y;
	float	max;
	int		color;

	params(&a, &b, param);
	x = b.x - a.x;
	y = b.y - a.y;
	max = img_max(check_neg(x), check_neg(y));
	x /= max;
	y /= max;
	color = find_color(b.z, a.z);
	while((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_put_pixel((mlx_image_t *)param, a.x, a.y, color);
		a.x += x;
		a.y += y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_start(t_point **map)
{
	int		x;
	int		y;
	
	y = 0;
	while(map[y])
	{
		x = 0;
		while (1)
		{
			if(map[y + 1])
				draw_line(map[y][x], map[y + 1][x], &map[0][0]);
			if(!map[y][x].last)
				draw_line(map[y][x], map[y][x + 1], &map[0][0]);
			if(map[y][x].last)
				break ;
			x++;	
		}
		y++;
	}
	//mlx_image_to_window(map[0][0].mlx_ptr, map[0][0].img_ptr, 400, 0);
}