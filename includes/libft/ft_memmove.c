/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:17:30 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/15 06:47:19 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned char		*csrc;
	size_t				a;

	if (!dest && !src)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	a = 0;
	if (cdest > csrc)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
	{
		while (a < n)
		{
			cdest[a] = csrc[a];
			a++;
		}
	}
	return (dest);
}
