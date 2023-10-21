/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:52:16 by alexandrine       #+#    #+#             */
/*   Updated: 2023/10/18 12:57:19 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	window_size(int key, t_info *info)
{
	if ((key == 0 && info->window_y <= 500) || \
			(key == 6 && info->window_x <= 500))
		return (1);
	if ((key == 1 && info->window_y > 1000) || \
			(key == 7 && info->window_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_info *info)
{
	static int	old_x;
	static int	old_y;

	if (info->window_x != 2560)
	{
		old_x = info->window_x;
		old_y = info->window_y;
	}
	if (info->window_x == 2560) 
		info->window_x = old_x;
	else
		info->window_x = 2560;
	if (info->window_y == 1400) 
		info->window_y = old_y;
	else
		info->window_y = 1400;
}

void	change_window_size(int key, t_info *info)
{
	if (window_size(key, info))
		return ;
	if (key == 6)
		info->window_x -= 100;
	if (key == 7)
		info->window_x += 100;
	if (key == 0)
		info->window_y -= 100;
	if (key == 1)
		info->window_y += 100;
	if (key == 3)
		full_screen(info);
}

void	new_window(int key, t_info *info)
{
	change_window_size(key, info);
	mlx_destroy_window(info->mlx, info->window);
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, info->window_x, \
									info->window_y, "FDF");
	info->shift_x = info->window_x / 3;
	info->shift_y = info->window_y / 3;
	breseham(info->matrix, info);
	mlx_key_hook(info->window, key_info, info);
	mlx_loop(info->mlx);
}

int	exit_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->window);
	err_exit(info, 0);
	return (0);
}
