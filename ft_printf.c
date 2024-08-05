/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:12:06 by rutatar           #+#    #+#             */
/*   Updated: 2023/11/05 18:10:21 by rutatar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_fcatch(char str)
{
	return (str == 'c' || str == 's'
		|| str == 'p' || str == 'd' || str == 'i'
		|| str == 'u' || str == 'x' || str == 'X'
		|| str == '%' );
}

static int	ft_type(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_string(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(ap, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	int		value;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_fcatch(s[i + 1]))
		{
			value = ft_type(ap, s[++i]);
			if (value == -1)
				return (-1);
			len += value - 1;
		}
		else if (ft_putchar(s[i]) == -1)
			return (-1);
		len++;
		i++;
	}
	va_end(ap);
	return (len);
}
