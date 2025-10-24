/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:57:54 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:41:14 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*schr;
	size_t			a;

	schr = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		if (schr[a] == (unsigned char)c)
			return ((void *)&schr[a]);
		a++;
	}
	return (0);
}
