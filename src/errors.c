/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:13:31 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 13:09:35 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mlx_err(char *err_mess, int fd)
{
	if (err_mess)
		ft_putendl_fd(err_mess, 2);
	if (fd)
		close (fd);
	exit(EXIT_FAILURE);
}

void	clean_exit(t_point *map, char *err_mess)
{
	if (map)
	{
		if (map->mlx_ptr)
			mlx_terminate(map->mlx_ptr);
		if (map->matrix)
			free_tab(map->matrix, (size_t)map->height);
		if (map->cam)
			free(map->cam);
		if (map->algo)
			free(map->algo);
		if (map->pos)
			free(map->pos);
		if (map->menu)
			free(map->menu);
		free(map);
	}
	if (err_mess)
		mlx_err(err_mess, 2);
	if (!err_mess)
		exit(EXIT_SUCCESS);
}
