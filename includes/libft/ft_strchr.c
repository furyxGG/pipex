/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 05:58:20 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/03 06:19:24 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a] && s[a] != (char)c)
		a++;
	if (s[a] == (char)c)
		return ((char *)s + a);
	return (0);
}
