/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:34:24 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 14:47:11 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	a;

	if (!s)
		return (0);
	a = 0;
	while (s[a])
		a++;
	return (a);
}

char	*ft_strchr_gnl(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;

	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen_gnl(s1)
				+ ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	if (s1)
	{
		while (s1[a])
			str[b++] = s1[a++];
	}
	if (s2)
	{
		a = 0;
		while (s2[a])
			str[b++] = s2[a++];
	}
	str[b] = '\0';
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*subptr;
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen_gnl(s))
	{
		subptr = (char *)malloc(1 * sizeof(char));
		if (!subptr)
			return (0);
		subptr[0] = '\0';
		return (subptr);
	}
	if (len > ft_strlen_gnl(s) - start)
		len = ft_strlen_gnl(s) - start;
	subptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!subptr)
		return (0);
	while (a < len)
	{
		subptr[a++] = s[start++];
	}
	subptr[a] = '\0';
	return (subptr);
}
