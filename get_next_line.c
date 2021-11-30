/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajana <ajana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:14:25 by ajana             #+#    #+#             */
/*   Updated: 2021/11/30 16:04:47 by ajana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 2);
	return (str);
}

char	*rest(char *s)
{
	char	*rest;
	int		i;
	int		s_len;

	i = 0;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	s_len = ft_strlen(&s[i]) + 1;
	rest = (char *)malloc(sizeof(char) * s_len);
	ft_strlcpy(rest, s + i, s_len);
	free(s);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*save;
	ssize_t		n;

	n = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	while (n && (!ft_strchr(buff, '\n')))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[n] = 0;
		save = ft_strjoin(save, buff);
	}
	free (buff);
	line = get_line(save);
	save = rest(save);
	return (line);
}
