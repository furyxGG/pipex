/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 05:02:06 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:38:32 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		a;
	int		b;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	a = 0;
	b = 0;
	while (s1[a])
	{
		newstr[b] = s1[a];
		a++;
		b++;
	}
	a = 0;
	while (s2[a])
	{
		newstr[b] = s2[a];
		a++;
		b++;
	}
	newstr[b] = '\0';
	return (newstr);
}
