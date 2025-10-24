/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:46:38 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/07/06 05:41:52 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_basenum(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr / 10 != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nbr)
{
	int		size;
	char	*ptr;

	size = ft_basenum(nbr);
	if (nbr == 0)
		return (ft_itoa(0));
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[size] = '\0';
	while (nbr != 0)
	{
		ptr[size - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		size--;
	}
	return (ptr);
}

int	ft_checkformat(va_list *lst, char c)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_printchr(va_arg(*lst, int));
	else if (c == 's')
		total += ft_printstr(va_arg(*lst, char *));
	else if (c == 'p')
		total += ft_printptr(va_arg(*lst, unsigned long long), -1);
	else if (c == 'd' || c == 'i' || c == 'u')
		total += ft_printnum(va_arg(*lst, int), c);
	else if (c == 'x' || c == 'X')
		total += ft_printhex(va_arg(*lst, int), c);
	else if (c == '%')
		total += write(1, "%", 1);
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		total;
	int		a;

	va_start(lst, format);
	if (!format)
		return (0);
	a = 0;
	total = 0;
	while (format[a])
	{
		if (format[a] == '%' && !format[a + 1])
			return (-1);
		if (format[a] == '%')
		{
			total += ft_checkformat(&lst, format[a + 1]);
			a++;
		}
		else
			total += write(1, &format[a], 1);
		a++;
	}
	va_end(lst);
	return (total);
}
