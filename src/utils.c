/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:48:41 by adube             #+#    #+#             */
/*   Updated: 2023/10/04 14:08:13 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_width(char *str, char c)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && str[i] != '\n')
			count++;
		while (str[i] != '\0' && !(str[i] == c))
			i++;
	}
	return (count);
}

void	iso(t_point *point, double angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}

void	scale_all(t_point *a, t_point *b, t_point *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z;
	b->z *= param->z;
}

void	params(t_point *a, t_point *b, t_point *param)
{
	scale_all(a, b, param);
	if (param->is_iso)
	{
		iso(a, param->angle);
		iso(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}

int find_color(float a, float b)
{
	int	color;

	if (b || a)
		color = 0xfc0345;
	else
		color = 0xBBFAFF;
	if ( b != a)
		color = 0xfc031c;
	return (color);
}