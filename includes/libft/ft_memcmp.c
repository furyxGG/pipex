/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:32:18 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:38:47 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1chr;
	unsigned char	*s2chr;
	size_t			a;

	if (!s1 && !s2)
		return (0);
	s1chr = (unsigned char *)s1;
	s2chr = (unsigned char *)s2;
	a = 0;
	while (a < n)
	{
		if (s1chr[a] != s2chr[a])
			return (s1chr[a] - s2chr[a]);
		a++;
	}
	return (0);
}
