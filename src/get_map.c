/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:42:11 by adube             #+#    #+#             */
/*   Updated: 2023/10/10 11:58:43 by adube            ###   ########.fr       */
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

int	get_info(char *file, t_point *map)
{
	char	*line;
	int		fd;
	int		flag;

	
	flag = 0;
	fd = open(file, O_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL && flag == 0)
			exit();
		if (line == NULL)
			break ;
		if (flag == 0)
			map_width(map, line);
		free(line);
		(map->height)++;
		flag = 42
	}
	close (fd);
}
s
void	read_map(char *map, char *file)
{
	char	*line;
	int		fd;

	get_info(map, file);
	init_matrix(map);
	fd = open(file, O_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_points(line, map);
		free(line);
	}
	max_height(map);
	close (fd);
}

void	get_map(t_point *map, char *file)
{
	char	*file_check;
	int		fd;

	file_check = NULL;
	file_check = ft_strrchr(file, '.');
	if (!file_check)
		clean_exit(map, KNYEL"file is invalid\n"KNRM);
	if (ft_strcmp(file_check, ".fdf") != 0)
		clean_exit(map, KNYEL"file has invalid extension\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_exit(map, KNYEL"file doesn't open or doesn't exist\n"KNRM);
	close (fd);
}