/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:27:47 by adube             #+#    #+#             */
/*   Updated: 2023/10/18 11:04:32 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	colors_mode1(t_point a, t_point b)
{
	if (b.z && a.z && b.z == a.z)
		return (get_random_color());
	if (b.z != a.z)
		return (get_random_color());
	return (get_random_white_color());
}

int	colors_mode2(t_point a, t_point b)
{
	if (b.z && a.z && b.z == a.z)
		return (get_random_white_color());
	if (b.z != a.z)
		return (get_random_white_color());
	return (get_random_color());
}

int	colors_mode3(t_info *info, t_point a, t_point b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (info->random_color)
			return (info->random_color);
		info->random_color = get_random_color();
		return (info->random_color);
	}
	return (get_random_white_color());
}

int	colors_mode4(t_info *info, t_point a, t_point b)
{
	if ((a.z || b.z) && a.z != b.z)
	{
		if (info->random_color)
			return (info->random_color);
		info->random_color = get_random_color();
		return (info->random_color);
	}
	if (info->random_color2)
		return (info->random_color2);
	info->random_color2 = get_random_color();
	return (info->random_color2);
}

int	colors_mode5(t_point a, t_point b)
{
	if (a.color >= 0)
		return (a.color);
	else if (b.color >= 0)
		return (b.color);
	return (0xFFFFFF);
}
