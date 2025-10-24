/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:00:00 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:41:40 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*nptr;
	int		a;

	nptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nptr)
		return (0);
	a = 0;
	while (s[a])
	{
		nptr[a] = s[a];
		a++;
	}
	nptr[a] = '\0';
	return (nptr);
}
