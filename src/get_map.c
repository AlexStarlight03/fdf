/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:42:11 by adube             #+#    #+#             */
/*   Updated: 2023/09/21 13:30:56 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_ext(char *ext, char *file)
{
	int	i;
	i = 0;
	
	while (file[i] != ".")
		i++;
	while (file[i] == ext[y] && file[i] != "\0" && ext[y] != "\0")
	{
		i++;
		y++;
	}
	if (file[i] == "\0" && ext[y] == "\0")
		return ;
	get_err(INVALID_MAP_EXT);
}

t_point	**alloc_tab(int fd)
{
	char	**map;
	char	*str;
	int		y;
	int		x;

	y = 1;
	str = get_next_line(fd);
	if (!str)
		get_error(INVALID_MAP_ERROR);
	x = nb_words(str, ' ');
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

int	get_points(char *line, char **map, int y)
{
	char	**points;
	int		x;

	points = split(line, ' ');
	x = 0;
	while (points[x])
	{
		number_valid(points[x]);
		map[y][x].z = ft_atoi(points[x]);
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].color = get_color(*(points + x));
		map[y][x].last = 0;
	}
	free(points);
	map[y][x--].last = 1;
	return (x);	
}

int	points_line(int fd, char **map)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	if (!line)
		get_err(INVALID_MAP_ERR);
	while (line)
	{
		get_points(line, map, y++);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (y);
}

t_point	**get_map(char *file)
{
	char	*path;
	int		fd;
	char	**map;
	int		y;

	check_ext(".fdf", file);
	path = ft_strjoin("./map", file);
	fd = open(path, O_RDONLY);
	ft_free(path);
	if (fd == -1)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			get_err(INVALID_MAP_ERROR);
	}
	map = alloc_tab(fd);
	y = points_line(fd, map);
	if (map[y])
		free(map[y]);
	map[y] = NULL;
	close(fd);
	return (map);
}