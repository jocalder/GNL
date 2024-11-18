/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:20 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/18 20:00:15 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
			return (free(buffer), free(line), NULL);
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (line);
}

char	*new_line(char *line)
{
	int		i;
	char	*str;

	if (!line || line[0] == '\0')
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (free(line), NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*update_buffer(char *line)
{
	char	*str;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (free(line), NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i) + 1);
	if (!str)
		return (free(line), NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (free(line), str);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*next_line;

	if (!fd)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!line[fd])
	{
		line[fd] = (char *)malloc(1);
		if (!line[fd])
			return (NULL);
		line[fd][0] = '\0';
	}
	line[fd] = read_line(line[fd], fd);
	if (!line[fd])
		return (NULL);
	next_line = new_line(line[fd]);
	line[fd] = update_buffer(line[fd]);
	return (next_line);
}
