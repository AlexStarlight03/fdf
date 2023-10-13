/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:19:11 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 13:38:05 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		pos_x(float x, t_point *map)
{
	if ((int)round(x) >= map->win_x)
		return ((int)x);
	return ((int) round(x));
}

int		pos_y(float y, t_point *map)
{
	if ((int)round(y) >= map->win_y)
		return ((int)y);
	return ((int) round(y));
}

void	set_pos(t_point *a, t_point *b, t_point *map)
{
	zoom(a, b, map);
	if(map->is_iso)
	{
		iso(a, map->angle);
		iso(b, map->angle);
	}
	a->x += map->shift_x;
	a->y += map->shift_y;
	b->x += map->shift_x;
	b->y += map->shift_y;
}