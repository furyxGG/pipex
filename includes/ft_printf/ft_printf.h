/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:50:06 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/05 02:09:25 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define NULL_STR "0x0"
#  define NULL_LEN 3
# elif __linux__
#  define NULL_STR "(nil)"
#  define NULL_LEN 5
# else
#  define NULL_STR "(null)"
#  define NULL_LEN 6
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_printstr(char *str);
int		ft_checkformat(va_list *lst, char c);
int		ft_printchr(char c);
int		ft_printptr(unsigned long long addr, int a);
int		ft_printnum(int nbr, char c);
char	*ft_uitoa(unsigned int nbr);
int		ft_basenum(unsigned int nbr);
char    *ft_itoa(int n);
int		ft_printhex(unsigned int nbr, char c);

#endif
