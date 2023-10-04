/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:42:11 by adube             #+#    #+#             */
/*   Updated: 2023/10/04 14:42:19 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



void	check_ext(char *ext, char *file)
{
	int	i;
	int	y;
	i = 0;
	y = 0;
	
	while (file[i] != '.')
		i++;
	while ((file[i] == ext[y]) && file[i] != '\0' && ext[y] != '\0')
	{
		i++;
		y++;
	}
	if (file[i] == '\0' && ext[y] == '\0')
		return ;
	exit(EXIT_FAILURE);
}

t_point	**alloc_tab(char *file)
{
	t_point	**map;
	char	*str;
	int		y;
	int		x;
	int		fd;

	fd = open(file, O_RDONLY);
	y = 0;
	str = get_next_line(fd);
	if (!str)
		mlx_err(INVALID_MAP_ERR);
	x = find_width(str, ' ');
	while (str)
	{
		y++;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	map = (t_point **)malloc(sizeof(t_point *) * (y + 1));
	while (y > 0)
		map[--y] = (t_point *)malloc(sizeof(t_point) * (x + 1));
	close(fd);
	return (map);
}

int	get_points(char *line, t_point **map, int y)
{
	char	**points;
	int		x;

	points = ft_split(line, ' ');
	x = 0;
	while (points[x])
	{
		map[y][x].z = ft_atoi(points[x]);
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].last = 0;
		
	}
	free(points);
	free(line);
	map[y][x--].last = 1;
	return (x);	
}

int	points_line(char *file, t_point **map)
{
	char	*line;
	int		y;
	int		fd;

	fd = open(file, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	if (!line)
		mlx_err(INVALID_MAP_ERR);
	while (line)
	{
		get_points(line, map, y++);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	map[y] = 0;
	close (fd);
	return (y);
}

t_point	**get_map(char *file)
{
	t_point	**map;
	int		y;

	check_ext(".fdf", file);
	map = alloc_tab(file);
	y = points_line(file, map);
	if (map[y])
		free(map[y]);
	map[y] = NULL;
	return (map);
}