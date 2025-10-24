/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 03:54:14 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:40:05 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		a;

	if (!s || !f)
		return (NULL);
	a = 0;
	new = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[a])
	{
		new[a] = f(a, s[a]);
		a++;
	}
	new[a] = '\0';
	return (new);
}
