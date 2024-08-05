/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:13:07 by rutatar           #+#    #+#             */
/*   Updated: 2023/11/05 18:08:31 by rutatar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (ft_string("(null)") == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long ul)
{
	int	res;
	int	check;

	check = 0;
	res = 0;
	if (ul < 16)
		res += write (1, "0x", 2);
	if (res == -1)
		return (-1);
	if (ul >= 16)
	{
		check = ft_pointer(ul / 16);
		if (check == -1)
			return (-1);
		res += check;
		check = write(1, &"0123456789abcdef"[ul % 16], 1);
		if (check == -1)
			return (-1);
		return (++res);
	}
	check = write(1, &"0123456789abcdef"[ul % 16], 1);
	if (check == -1)
		return (-1);
	return (++res);
}

int	ft_int(int number)
{
	int	len;
	int	value;

	len = 0;
	if (number == 0)
		return (ft_putchar('0'));
	if (number == -2147483648)
		return (ft_string("-2147483648"));
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		number *= -1;
	}
	if (number >= 10)
	{
		value = ft_int(number / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar("0123456789"[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int num)
{
	int		len;
	int		value;
	char	*b;

	b = "0123456789";
	len = 0;
	if (num > 9)
	{
		value = ft_unsigned(num / 10);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (ft_putchar(b[num % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex(unsigned int num, char d)
{
	int	len;
	int	value;

	len = 0;
	if (num >= 16)
	{
		value = ft_hex(num / 16, d);
		if (value == -1)
			return (-1);
		len += value;
	}
	if (d == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[num % 16]) == -1)
			return (-1);
	}
	if (d == 'x')
	{
		if (ft_putchar("0123456789abcdef"[num % 16]) == -1)
			return (-1);
	}
	return (len + 1);
}
