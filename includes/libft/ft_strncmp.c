/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 07:02:48 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/05/31 13:53:15 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if ((unsigned char)s1[a] != (unsigned char)s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		if (!s1[a])
			return (0);
		a++;
	}
	return (0);
}
