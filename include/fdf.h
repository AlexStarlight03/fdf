/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:35:07 by adube             #+#    #+#             */
/*   Updated: 2023/09/21 10:46:44 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include "../lib/libft/libft.h"
# include "../lib//MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int	main(int argc, char **argv);
void	get_map(char *file);

#endif