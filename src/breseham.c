/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breseham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:23:49 by adube             #+#    #+#             */
/*   Updated: 2023/10/18 11:03:48 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_iswhitespace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

float	max_float(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

void	line(t_point a, t_point b, t_info *info)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_info(&a, &b, info);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = max_float(abs_float_value(step_x), abs_float_value(step_y));
	step_x /= max;
	step_y /= max;
	color = get_color(info, a, b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(info->mlx, info->window, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > info->window_x || a.y > info->window_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	breseham(t_point **matrix, t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], info);
			if (!matrix[y][x].last)
				line(matrix[y][x], matrix[y][x + 1], info);
			if (matrix[y][x].last)
				break ;
			x++;
		}
		y++;
	}
	print_menu(info);
}
