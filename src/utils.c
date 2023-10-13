/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:48:41 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 12:44:29 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



int	points_in_line(char *line, t_point *map, int y)
{
	char	**points;
	int		x;

	if (!line)
		clean_exit(map, "This map is invalid");
	points = ft_split(line, ' ');
	x = 0;
	while (points[x])
	{
		if_valid(points[x]);
		map->matrix[y][x].z = ft_atoi(points[x]);
		map->matrix[y][x].x = x;
		map->matrix[y][x].y = y;
		map->matrix[y][x].color = find_color(*(points + x));
		map->matrix[y][x].last = 0;
		free(points[x++]);
	}
	free(points);
	map->matrix[y][--x].last = 1;
	return (x);
}

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

int find_color(t_point *map, float a, float b)
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