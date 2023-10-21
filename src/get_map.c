/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:42:11 by adube             #+#    #+#             */
/*   Updated: 2023/10/20 22:41:46 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]) == 1)
			i++;
		else if (ft_iswhitespace(str[i]) == 0)
		{
			count++;
			while (ft_iswhitespace(str[i]) == 0)
				i++;
		}
	}
	return (count);
}

void	check_ext(char *ext, char *file)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (file[i] != '.')
		i++;
	while (file[i] == ext[y] && file[i] != '\0' && ext[y] != '\0')
	{
		i++;
		y++;
	}
	if (file[i] == '\0' && ext[y] == '\0')
		return ;
	err_exit(0, "Invalid map");
}

t_point	**alloc_tab(char *file)
{
	t_point	**new_map;
	char	*line;
	int		y;
	int		x;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	x = count(line);
	y = 1;
	while (42)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		y++;
	}
	free(line);
	new_map = (t_point **)malloc(sizeof(t_point *) * (y + 1));
	while (y > 0)
		new_map[--y] = (t_point *)malloc(sizeof(t_point) * (x + 1));
	close(fd);
	return (new_map);
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
		map[y][x].color = get_color_from_line(*(points + x));
		map[y][x].last = 0;
		free(points[x++]);
	}
	free(points);
	map[y][--x].last = 1;
	return (x);
}

t_point	**get_map(char *file)
{
	char	*line;
	int		fd;
	t_point	**map;
	int		y;

	check_ext(".fdf", file);
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		err_exit(0, "Invalid map");
	map = alloc_tab(file);
	y = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_points(line, map, y++);
		free(line);
	}
	free(line);
	map[y] = NULL;
	close(fd);
	return (map);
}
