/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:50:43 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:37:19 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_basecount(int n)
{
	int	a;
	int	b;

	a = 1;
	b = n;
	while (n / 10 != 0)
	{
		a++;
		n = n / 10;
	}
	if (b < 0)
		return (a + 1);
	return (a);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		a;
	int		sign;
	long	c;

	a = ft_basecount(n);
	c = (long)n;
	sign = 1;
	str = (char *)malloc((a + 1) * sizeof(char));
	if (!str)
		return (0);
	str[a] = '\0';
	if (c < 0)
	{
		c = c * -1;
		sign = -1;
	}
	while (a)
	{
		str[a-- - 1] = (c % 10) + 48;
		c = c / 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
