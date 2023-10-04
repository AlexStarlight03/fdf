/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:05:39 by adube             #+#    #+#             */
/*   Updated: 2023/10/04 12:57:43 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_call_prep(char *s)
{
	t_index	index;
	char	*new_line;

	index.i = 0;
	index.j = 0;
	while (s[index.i] && s[index.i] != '\n')
		index.i++;
	if (!s[index.i])
	{
		free(s);
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(s) - index.i + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	index.i++;
	while (s[index.i])
		new_line[index.j++] = s[index.i++];
	if (*new_line == 0)
	{
		free (new_line);
		new_line = NULL;
	}
	free (s);
	return (new_line);
}

char	*define_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && str[i])
		line[i++] = '\n';
	return (line);
}

char	*join_free(char *result, char *buffer)
{
	char	*joined;

	joined = str_join(result, buffer);
	free(result);
	if (!joined)
	{
		free(result);
		free(joined);
		return (NULL);
	}
	if (*joined == 0)
	{
		free(joined);
		joined = NULL;
	}
	return (joined);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		count_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	count_read = 1;
	while (count_read != 0 && !string_search(buffer, '\n'))
	{
		count_read = read(fd, buffer, BUFFER_SIZE);
		if (count_read == -1)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[count_read] = 0;
		result = join_free(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*buffer[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = define_line(buffer[fd]);
	buffer[fd] = next_call_prep(buffer[fd]);
	return (line);
}
