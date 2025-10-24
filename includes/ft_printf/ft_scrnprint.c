/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrnprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:01:03 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/07/06 05:58:30 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	a;
	int	tot;

	tot = 0;
	if (!str)
	{
		tot = write(1, "(null)", 6);
		return (tot);
	}
	a = 0;
	while (str[a])
	{
		tot += write(1, &str[a], 1);
		a++;
	}
	return (tot);
}

int	ft_printchr(char c)
{
	int	a;

	a = write(1, &c, 1);
	return (a);
}

int	ft_printptr(unsigned long long addr, int a)
{
	int	tot;

	if (!addr)
		return (write(1, NULL_STR, NULL_LEN));
	tot = 0;
	if (a < 0)
		tot += ft_printstr("0x");
	if (addr >= 16)
		tot += ft_printptr(addr / 16, 1);
	tot += write(1, &"0123456789abcdef"[addr % 16], 1);
	return (tot);
}

int	ft_printnum(int nbr, char c)
{
	char	*str;
	int		len;

	str = NULL;
	if (c == 'd' || c == 'i')
		str = ft_itoa(nbr);
	else if (c == 'u')
		str = ft_uitoa((unsigned int)nbr);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_printhex(unsigned int nbr, char c)
{
	int	tot;

	tot = 0;
	if (c == 'x')
	{
		if (nbr >= 16)
			tot += ft_printhex(nbr / 16, c);
		tot += write(1, &"0123456789abcdef"[nbr % 16], 1);
	}
	else if (c == 'X')
	{
		if (nbr >= 16)
			tot += ft_printhex(nbr / 16, c);
		tot += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	}
	return (tot);
}
