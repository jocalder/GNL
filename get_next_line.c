/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:33:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/31 19:04:37 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_line(char *line, int fd)
{
	char	*buffer;
	size_t	bytes;

	bytes = 0;
	bytes = read()
}
char	*new_line(char *line, int fd)
{
	int	i;
	int	j;
	char	*str;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line)
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(line)  + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	j = 0;
	while (str[j])
	{
		str[j] = line[i]
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffersize;
	char	
}
