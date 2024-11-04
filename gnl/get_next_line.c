/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:14:07 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/04 18:42:17 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	ft_strlenchr(const char *s, const char c)
{
	const char	*tmp;

	if (!s)
		return (0);
	tmp = s;
	while (*tmp && *tmp != c)
		tmp++;
	return (tmp - s + (*tmp == c));
}

static int	add_line(char *buffer, int fd, char **line)
{
	int	byte_read;

	byte_read = 0;
	if (buffer[0] == 0)
		byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read < 0)
		return (-1);
	buffer[byte_read] = '\0';
	if (byte_read == 0)
	{
		if (line == NULL || *line == 0)
			return (-1);
		return (1);
	}
	return (0);
}

static int	extract_line(char *buffer, int *len_line, char **line)
{
	int		len_buffer;
	char	*new;

	len_buffer = ft_strlenchr(buffer, '\n');
	if (len_buffer == 0)
		return (0);
	*len_line += len_buffer;
	new = ft_realloc(*line, (*len_line + 1));
	if (!new)
		return (-1);
	if (*line == NULL)
		new[0] = '\0';
	ft_strlcat(new, buffer, *len_line + 1);
	new[*len_line] = '\0';
	*line = new;
	if (buffer[len_buffer - 1] == '\n')
	{
		ft_memmove(buffer, buffer + len_buffer, ft_strlen(buffer) - len_buffer
			+ 1);
		return (1);
	}
	buffer[0] = '\0';
	return (2);
}

static char	*get_line(char *buffer, int fd)
{
	char	*line;
	int		line_len;
	int		check;

	check = 0;
	line = NULL;
	line_len = 0;
	while (1 == 1)
	{
		check = extract_line(buffer, &line_len, &line);
		if (check == 1)
			return (line);
		else if (check == -1)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		check = add_line(buffer, fd, &line);
		if (check == -1)
			return (NULL);
		if (check == 1)
			return (line);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = get_line(buffer, fd);
	return (line);
}
