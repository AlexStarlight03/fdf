/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:35:07 by adube             #+#    #+#             */
/*   Updated: 2023/10/20 20:02:50 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"

# define MAX_COLOR_HEX 16777215
# define VIOLET_HEX 0x8F00FF
# define YELLOW_HEX 0xFFFF00
# define BLUE_HEX 0x177E89

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			last;
	int			color;
}				t_point;

typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_info
{
	int			random_color;
	int			random_color2;
	int			color_style;
	int			has_colors;
	int			map_width;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_iso;
	double		angle;
	t_img		img;
	t_point		**matrix;
	int			window_x;
	int			window_y;
	void		*mlx;
	void		*window;
}				t_info;

int		ft_iswhitespace(int c);
float	max_float(float x, float y);
void	line(t_point a, t_point b, t_info *info);
void	breseham(t_point **matrix, t_info *info);

int		colors_mode1(t_point a, t_point b);
int		colors_mode2(t_point a, t_point b);
int		colors_mode3(t_info *info, t_point a, t_point b);
int		colors_mode4(t_info *info, t_point a, t_point b);
int		colors_mode5(t_point a, t_point b);

int		get_color_from_line(char *s);
void	set_color_styles(t_info *info);
int		get_random_color(void);
int		get_random_white_color(void);
int		get_color(t_info *info, t_point a, t_point b);

int		count(char *str);
void	check_ext(char *ext, char *file);
t_point	**alloc_tab(char *file);
int		get_points(char *line, t_point **map, int y);
t_point	**get_map(char *file);

int		is_key(int key);
void	do_key(int key, t_info *info);
int		key_info(int key, t_info *info);

int		map_color(t_point **map);
int		map_width(t_point **map);
void	init_start(t_info *info, t_point **map);
int		main(int argc, char **argv);

int		index_of(char *s, char c);
int		in_string(char *s, char c);
int		hex_to_int(char *s);
int		free_ptr(void **ptr);
int		free_tab(t_point ***ptab);

int		pos_x(float x, t_info *info);
int		pos_y(float y, t_info *info);
float	abs_float_value(float x);

void	err_exit(t_info *info, char *err_mess);
void	zoom(t_point *a, t_point *b, t_info *info);
void	set_info(t_point *a, t_point *b, t_info *info);
void	iso(t_point *point, double angle);
void	print_menu(t_info *info);

int		window_size(int key, t_info *info);
void	full_screen(t_info *info);
void	change_window_size(int key, t_info *info);
void	new_window(int key, t_info *info);
int		exit_window(t_info *info);

#endif