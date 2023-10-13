/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:14:39 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 10:41:49 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	*alloc_tab(char *file)
{
	t_point	*map;
	char	*str;
	int		y;
	int		x;
	int		fd;

	fd = open(file, O_RDONLY);
	y = 0;
	str = get_next_line(fd);
	if (!str)
		mlx_err(INVALID_MAP_ERR, 2);
	x = find_width(str, ' ');
	while (str)
	{
		y++;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	map->matrix = (t_point **)malloc(sizeof(t_point *) * (++y + 1));
	while (y > 0)
		map->matrix[--y] = (t_point *)malloc(sizeof(t_point) * (x + 1));
	close(fd);
	return (map);
}

t_point	*get_info(char *file, t_point *map)
{
	char	*line;
	int		fd;
	int		flag;

	
	flag = 0;
	fd = open(file, O_RDONLY);
	map = alloc_tab(file);
	line = get_next_line(fd);
	while (42)
	{
		line = get_next_line(fd);
		if (!line  && flag == 0)
			exit(EXIT_FAILURE);
		if (!line)
			break ;
		if (flag == 0)
			find_width(map, line);
		free(line);
		(map->height)++;
		flag = 42;
	}
	close (fd);
	return(map);
}
