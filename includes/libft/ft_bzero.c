/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:08:30 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/06/11 12:36:01 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*chr;
	size_t			a;

	chr = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		chr[a] = 0;
		a++;
	}
}
