/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/06 10:38:00 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	
}


int	main(int argc, char **argv)
{
	t_point **map;
	t_point	*param;

	if (argc != 2)
	{	
		ft_putstr_fd("Please have 2 arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map(argv[1]);
	param = &map[0][0];
	param->mlx_ptr = mlx_init(2000, 1000, "FDF", true);
	if (!param->mlx_ptr)
		mlx_strerror(mlx_errno);
	param->img_ptr = mlx_new_image(param->mlx_ptr, 2000, 2000);
	if (!param->img_ptr)
	{
		mlx_close_window(param->mlx_ptr);
		mlx_strerror(mlx_errno);
		return(EXIT_FAILURE);
	}
	if ((mlx_image_to_window(param->mlx_ptr, param->img_ptr, 0, 0)) == -1)
	{
		mlx_close_window(param->mlx_ptr);
		mlx_strerror(mlx_errno);
		return(EXIT_FAILURE);
	}
	draw_start(map);
	mlx_loop_hook(param->mlx_ptr, ft_hook, param->mlx_ptr);
	mlx_loop(param->mlx_ptr);
	mlx_terminate(param->mlx_ptr);
	return (EXIT_SUCCESS);
}