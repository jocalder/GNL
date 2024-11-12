/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:33:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/12 16:33:53 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		printf("Error: No se asigno buffer\n");
		return (NULL);
	}
	printf("buffer asignado correctamente\n");
	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			printf("error en la lectura\n");
			free(buffer);
			return (NULL);
		}
		printf("bytes leidos: %ld\n", bytes);
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
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
	printf("Hasta el salto de línea: %s\n", line);
	str = (char *)malloc((ft_strlen(line) + 2) * sizeof(char));
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
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i) + 1);
	if (!str)
	{		
		free(line);
		return (NULL);
	}
	j = 0;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char	*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = read_line(line, fd);
	if (!line)
		return (NULL);
	next_line = new_line(line);
	line = update_buffer(line);
	return (next_line);
}

int main()
{
	int fd;
	char *line;

	fd = open("quijote.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}