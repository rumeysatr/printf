/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:12:29 by rutatar           #+#    #+#             */
/*   Updated: 2023/11/05 14:54:51 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_string(char *s);
int	ft_unsigned(unsigned int num);
int	ft_hex(unsigned int num, char d);
int	ft_pointer(unsigned long ul);
int	ft_int(int number);
int	ft_printf(const char *s, ...);

#endif