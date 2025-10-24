/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:49:54 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:38:13 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (!*little)
		return ((char *)big);
	b = 0;
	while (big[b])
	{
		l = 0;
		while (big[b + l] == little[l] && (b + l) < len)
		{
			if (!little[l])
			{
				return ((char *)&big[b]);
			}
			l++;
		}
		if (!little[l])
			return ((char *)&big[b]);
		b++;
	}
	return (0);
}
