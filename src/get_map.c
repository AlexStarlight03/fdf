/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:42:11 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 13:08:50 by adube            ###   ########.fr       */
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

void	get_map(t_point *map, char *file)
{
	char	*file_check;
	int		fd;
	
	file_check = ft_strrchr(file, '.');
	if (!file_check)
		clean_exit(map, KYEL"file is invalid\n"KNRM);
	if (ft_strcmp(file_check, ".fdf") != 0)
		clean_exit(map, KYEL"file has invalid extension\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_exit(map, KYEL"file doesn't open or doesn't exist\n"KNRM);
	close (fd);
}