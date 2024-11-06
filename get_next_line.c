/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:33:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/06 19:29:17 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	bytes;

	if (!line || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	bytes = 1;
	while (!ft_strchr(line, '\n') && fd > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);

}

char	*new_line(char *line)
{
	int	i;
	int	j;
	char	*str;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc((ft_strlen(line)  + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*update_buffer(char *line)
{
	char	*str;
	int		i;

	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(line) - i) + 1);
	if (!str)
	{		free(str);
		return (NULL);
	}
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (str[i] == '\n')
		i++;
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char	*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(line, fd);
	next_line = new_line(line);
	line = update_buffer(line);
	return (next_line);
}


