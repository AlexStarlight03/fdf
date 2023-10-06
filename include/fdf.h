/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:35:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/06 10:38:37 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#endif


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include "../lib/libft/libft.h"
# include "../lib//MLX42/include/MLX42/MLX42.h"
# include <math.h>

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		last;
	
	int		color;
	int		scale;
	int		z_scale;
	int		shift_x;
	int		shift_y;
	int		is_iso;
	double	angle;
	int		win_x;
	int		win_y;
	mlx_t	*mlx_ptr;
	void	*win_ptr;

	char	*adrr;
	mlx_image_t	*img_ptr;
}			t_point;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# define SCALE 40
# define Z_SCALE 1
# define IS_ISO 1
# define ANGLE 0.523599
# define WIN_X 2000
# define WIN_Y 1000
# define SHIFT_X WIN_X / 3
# define SHIFT_y WIN_Y / 3

# define INPUT_ERR "please enter a valid .fdf map"
# define MALLOC_ERR "there was an error in the malloc"
# define FILE_ERR "file was not found"
# define INVALID_MAP_ERR "the map is invalid"
# define INVALID_MAP_EXT "please enter a map with .fdf extension"
# define END_MESS "the program closed successfully"

int	main(int argc, char **argv);
void	mlx_err(void *ptr);
t_point	**get_map(char *file);
int find_color(float a, float b);
int		set_base(t_point *param);
void	print_menu(t_point param);
void	params(t_point *a, t_point *b, t_point *param);
int find_color(float a, float b);
void	scale_all(t_point *a, t_point *b, t_point *param);
void	iso(t_point *point, double angle);
char	*get_next_line(int fd);
char	*str_join(char const *s1, char const *s2);
char	*string_search(const char *s, char c);
int		find_width(char *str, char c);
void	draw_start(t_point **map);


#endif