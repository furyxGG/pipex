/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 04:42:25 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/05/31 05:49:05 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	a;

	a = 0;
	destlen = ft_strlen(dst);
	if (size <= destlen)
		return (size + ft_strlen(src));
	while (src[a] && destlen + a < size - 1)
	{
		dst[destlen + a] = src[a];
		a++;
	}
	dst[destlen + a] = '\0';
	return (destlen + ft_strlen(src));
}
