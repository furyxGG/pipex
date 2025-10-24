/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:21:01 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:37:58 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subptr;
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		subptr = (char *)malloc(1 * sizeof(char));
		if (!subptr)
			return (0);
		subptr[0] = '\0';
		return (subptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
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
