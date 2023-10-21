/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:22:55 by adube             #+#    #+#             */
/*   Updated: 2023/10/20 22:41:12 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	err_exit(t_info *info, char *err_mess)
{
	if (info && info->matrix != NULL)
		free_tab(&info->matrix);
	if (err_mess)
	{
		ft_putendl_fd(err_mess, 2);
		exit(1);
	}
	exit(0);
}

void	zoom(t_point *a, t_point *b, t_info *info)
{
	a->x *= info->scale;
	a->y *= info->scale;
	b->x *= info->scale;
	b->y *= info->scale;
	a->z *= info->z_scale;
	b->z *= info->z_scale;
}

void	set_info(t_point *a, t_point *b, t_info *info)
{
	zoom(a, b, info);
	if (info->is_iso)
	{
		iso(a, info->angle);
		iso(b, info->angle);
	}
	a->x += info->shift_x;
	a->y += info->shift_y;
	b->x += info->shift_x;
	b->y += info->shift_y;
}

void	iso(t_point *point, double angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}

void	print_menu(t_info *info)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(info->mlx, info->window, 10, 5, 0x03fc35, menu);
	menu = "5, space: 3d/2d mode; +, -: zoom";
	mlx_string_put(info->mlx, info->window, 10, 20, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(info->mlx, info->window, 10, 35, 0x03fc35, menu);
	menu = "f: toggle full screen mode";
	mlx_string_put(info->mlx, info->window, 10, 50, 0x03fc35, menu);
}
