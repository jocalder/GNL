/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:30:43 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/12 16:23:45 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
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
	if (!line)
		return (NULL);
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

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*dup;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	dup = ptr;
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	return (ptr);
}
