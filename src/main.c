/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/04 14:24:59 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_menu(t_point param)
{
	char	*menu;

	menu = "use the number pad";
	mlx_put_string(param.mlx_ptr, menu, 10, 10);
}

//static void ft_hook(void* param)
//{
//	const mlx_t* mlx = param;

//	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
//}

void	set_base(t_point *param)
{
	param->scale = 40;
	param->z_scale = 1;
	param->is_iso = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init(param->win_x, param->win_y, "FDF", true);
	if (!param->mlx_ptr)
		mlx_err("mlx has failed... :(");
	//param->win_ptr = mlx_image_to_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
	//if (!param->win_ptr)
	//	mlx_err("mlx has failed... :(");
	param->img_ptr = mlx_new_image(param->mlx_ptr, 2000, 2000);
	if (!param->img_ptr)
		mlx_err("mlx has failed... :(");
	//param->adrr = mlx_get_data_addr(param->img_ptr, &param->pixel_per_bit, &param->line_size, &param->endian);
}

int	main(int argc, char **argv)
{
	t_point **map;

	if (argc != 2)
	{	
		ft_putstr_fd("Please have 2 arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map(argv[1]);
	set_base(&map[0][0]);
	//mlx_loop_hook(map->mlx_ptr, ft_hook, map->mlx_ptr);
	//mlx_loop(map->mlx_ptr);
	//mlx_terminate(map->mlx_ptr);
	return (EXIT_SUCCESS);
	
}