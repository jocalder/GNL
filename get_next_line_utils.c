/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:30:43 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/08 19:09:04 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *line, int c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == (unsigned char)c)
			return ((char *)&line[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&line[i]);
	return (NULL);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!line || !buffer)
		return (NULL);
	str = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free(line);
	return (str);
}
