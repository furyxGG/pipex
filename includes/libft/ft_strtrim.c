/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 05:08:13 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:34:07 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		a;
	int		b;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	a = 0;
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	b = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[a]) && s1[a])
		a++;
	while (ft_strchr(set, s1[b]) && b > a)
		b--;
	newstr = ft_substr(s1, a, b - a + 1);
	return (newstr);
}
