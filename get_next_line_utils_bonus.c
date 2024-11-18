/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:54:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/11/18 17:00:45 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(char *line, int c)
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

	if (!buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (!str)
		return (free(line), NULL);
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
	return (free(line), str);
}
