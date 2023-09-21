/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:29:07 by adube             #+#    #+#             */
/*   Updated: 2023/09/21 13:30:54 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	
	if (argc != 2)
	{	
		ft_putstr_fd("Please have 2 arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	
	get_map(argv[1]);
}