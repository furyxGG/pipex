/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:35:07 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/15 06:47:29 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dstchr;
	unsigned char	*srcchr;
	size_t			a;

	if (!dest && !src)
		return (NULL);
	dstchr = (unsigned char *)dest;
	srcchr = (unsigned char *)src;
	a = 0;
	while (a < n)
	{
		dstchr[a] = srcchr[a];
		a++;
	}
	return (dest);
}
