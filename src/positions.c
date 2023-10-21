/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:52:10 by adube             #+#    #+#             */
/*   Updated: 2023/10/18 12:54:22 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	pos_x(float x, t_info *info)
{
	if ((int)round(x) >= info->window_x)
		return ((int) x);
	return ((int) round(x));
}

int	pos_y(float y, t_info *info)
{
	if ((int) round(y) >= info->window_y)
		return ((int) y);
	return ((int) round(y));
}

float	abs_float_value(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
