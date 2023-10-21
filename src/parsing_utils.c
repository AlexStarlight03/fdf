/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:13:33 by adube             #+#    #+#             */
/*   Updated: 2023/10/18 12:39:13 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	free_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (0);
}

int	free_tab(t_point ***ptab)
{
	t_point	**tab;

	if (!ptab || !(*ptab))
		return (0);
	tab = *ptab;
	while (*(tab))
	{
		free_ptr((void **)tab);
		tab++;
	}
	free_ptr((void **)ptab);
	return (0);
}

int	index_of(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	in_string(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (1);
}

int	hex_to_int(char *s)
{
	char	*hex;
	int		res;
	int		i;

	res = 0;
	hex = "0123456789abcdef";
	i = 0;
	while (s[i])
	{
		res = res * 16 + index_of(hex, ft_tolower(s[i]));
		i++;
	}
	return (res);
}
