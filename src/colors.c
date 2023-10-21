/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:55 by adube             #+#    #+#             */
/*   Updated: 2023/10/18 11:04:57 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_color_from_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ',')
		i++;
	if (!s[i])
		return (-1);
	return (hex_to_int(s + i + 2));
}

void	set_color_styles(t_info *info)
{
	info->color_style = (info->color_style + 1) % (4 + info->has_colors);
	info->random_color = 0;
	info->random_color2 = 0;
}

int	get_random_color(void)
{
	int	random;

	random = rand() % MAX_COLOR_HEX;
	return (random);
}

int	get_random_white_color(void)
{
	int	arr[6];

	arr[0] = 0xfffafa;
	arr[1] = 0xEEEEFF;
	arr[2] = 0xfdfcfa;
	arr[3] = 0xf5f5f5;
	arr[4] = 0xe5e4e2;
	arr[5] = 0xfffafa;
	return (arr[rand() % 6]);
}

int	get_color(t_info *info, t_point a, t_point b)
{
	if (info->color_style == 4)
		return (colors_mode5(a, b));
	if (info->color_style == 3)
		return (colors_mode4(info, a, b));
	if (info->color_style == 2)
		return (colors_mode3(info, a, b));
	if (info->color_style == 1)
		return (colors_mode2(a, b));
	else
		return (colors_mode1(a, b));
	return (0);
}
