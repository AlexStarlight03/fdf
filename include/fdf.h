/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:35:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/13 13:49:31 by adube            ###   ########.fr       */
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
# include <stdbool.h>

#define bool int
#define true 1
#define false 0


# define WIDTH 960
# define HEIGHT 540

# define KNRM "\x1B[m"
# define KRED "\x1B[31m"
# define KYEL "\x1B[33m"

typedef enum scheme
{
	standard,
	icewindale,
	phandelver,
	strahd,
	avernus,
}	t_scheme;

typedef enum view
{
	iso,
	top_view,
}	t_view;

typedef struct s_menu
{
	mlx_image_t		*menu_img;
	mlx_texture_t	*menu_txt;
}	t_menu;

typedef struct s_cam
{
	t_view	proj;
	double	zoom;
}	t_cam;

typedef struct s_algo
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	ptp;
	double	delta_max;
	double	pixel;
}	t_algo;

typedef struct s_line
{
	double	sx;
	double	sy;
	double	sz;
	double	ex;
	double	ey;
	double	ez;
	double	proj_sx;
	double	proj_sy;
	double	proj_sz;
	double	proj_ex;
	double	proj_ey;
	double	proj_ez;
}			t_line;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		last;
	t_point		**matrix;
	
	t_scheme	color;
	int		scale;
	int		z_scale;
	double		shift_x;
	double		shift_y;
	int		is_iso;
	double	angle;
	int		win_x;
	int		win_y;
	double	height;
	double	width;
	t_cam	*cam;
	t_line	*pos;
	t_menu	*menu;
	t_algo	*algo;
	mlx_image_t	*img_ptr;
	keys_t	*keys;
	mlx_t	*mlx_ptr;
}		t_point;

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


//---main--
int	main(int argc, char **argv);
bool ft_init(t_point *map, char *file);
void ft_hook(void* param);

//---color_scheme--


//----hooks--
void	ft_colors_hook(t_point *map, keys_t key)
void	ft_projection_hook(t_point *map, keys_t key);
void	ft_key_hooks(mlx_key_data_t keydata, void *param);

//----breseham--
float	check_neg(float i);
float	img_max(float x, float y);
void	draw_line(t_point a, t_point b, t_point *map);
void	draw_start(t_point *map);

//---errors--
void	mlx_err(char *err_mess, int fd);
void	clean_exit(t_point *map, char *err_mess);

//---get_map--
void	check_ext(char *ext, char *file);
void	get_map(t_point *map, char *file);

//---init--
t_cam	*ft_init_cam(void);
t_algo	*ft_init_algo(void);
t_point	*ft_init_map(void);

//---parsing--
t_point	*alloc_tab(char *file);
t_point	*get_info(char *file, t_point *map);


//---position--
int		pos_x(float x, t_point *map);
int		pos_y(float y, t_point *map);
void	set_pos(t_point *a, t_point *b, t_point *map);

//---utils--
int	points_in_line(char *line, t_point *map, int y);
int	find_width(char *str, char c);
void	iso(t_point *point, double angle);
void	scale_all(t_point *a, t_point *b, t_point *param);
void	params(t_point *a, t_point *b, t_point *param);
int find_color(t_point *map, float a, float b);

#endif