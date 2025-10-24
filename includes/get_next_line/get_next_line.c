/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 05:35:59 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:30:11 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*takedata(int fd, char *allines)
{
	char	*buff;
	char	*tmp;
	int		bytesize;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytesize = 1;
	while (!ft_strchr_gnl(allines, '\n') && bytesize > 0)
	{
		bytesize = read(fd, buff, BUFFER_SIZE);
		if (bytesize == -1)
		{
			free(allines);
			free(buff);
			return (NULL);
		}
		buff[bytesize] = '\0';
		tmp = ft_strjoin_gnl(allines, buff);
		free(allines);
		allines = tmp;
	}
	free(buff);
	return (allines);
}

static char	*giveline(char **allines)
{
	char	*newpos;
	char	*line;
	int		a;

	a = 0;
	while ((*allines)[a] && (*allines)[a] != '\n')
		a++;
	if ((*allines)[a] == '\n')
		a++;
	line = ft_substr_gnl(*allines, 0, a);
	newpos = ft_substr_gnl(*allines, a, ft_strlen_gnl(*allines) - a);
	free(*allines);
	*allines = newpos;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*allines[4048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	allines[fd] = takedata(fd, allines[fd]);
	if (!allines[fd] || allines[fd][0] == '\0')
	{
		free(allines[fd]);
		allines[fd] = NULL;
		return (NULL);
	}
	line = giveline(&allines[fd]);
	return (line);
}
