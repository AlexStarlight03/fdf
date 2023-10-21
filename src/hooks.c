/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:34:21 by alexandrine       #+#    #+#             */
/*   Updated: 2023/10/18 12:50:40 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 91 || key == 28 || key == 84 || key == 19 || \
	key == '~' || key == '}' || key == '{' || key == '|' || \
	key == 87 || key == 23 || key == 86 || key == 21 || \
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_info *info)
{
	if (key == 24 || key == 69)
		info->scale += 3;
	if (key == 27 || key == 78)
		info->scale -= 3;
	if (key == 91 || key == 28)
		info->z_scale += 1;
	if (key == 84 || key == 19)
		info->z_scale -= 1;
	if (key == '~')
		info->shift_y -= 10;
	if (key == '}')
		info->shift_y += 10;
	if (key == '{')
		info->shift_x -= 10;
	if (key == '|')
		info->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		info->is_iso = !info->is_iso;
	if (key == 86 || key == 21)
		info->angle += 0.05;
	if (key == 88 || key == 22)
		info->angle -= 0.05;
}

int	key_info(int key, t_info *info)
{
	if (is_key(key))
	{
		mlx_clear_window(info->mlx, info->window);
		do_key(key, info);
		print_menu(info);
		breseham(info->matrix, info);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, info);
	if (key == '5')
	{
		mlx_destroy_window(info->mlx, info->window);
		err_exit(info, 0);
	}
	return (0);
}
