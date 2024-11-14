/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:33:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/14 18:51:47 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *line, int fd)
{
	static char	*buffer;
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
			break;
		if (bytes == -1)
			return (free(buffer), free(line), NULL);
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);

}

char	*new_line(char *line)
{
	int	i;
	char	*str;

	if (!line || line[0] == '\0')
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
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
	if (line[i] ==  '\0')
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
	static char	*line;
	char	*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
	{
		line = (char *)malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = read_line(line, fd);
	if (!line)
		return (NULL);
	next_line = new_line(line);
	line = update_buffer(line);
	return (next_line);
}
