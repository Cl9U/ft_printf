/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:29:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/20 22:23:59 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list args;

	i = 0;
	count = 0;
	va_start(args ,format);
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar_n(format[i]);
		else if (format[i] == '%' && format[i + 1])
			count += ft_parse_n(&format[i++], &args);
		i++;
	}
	va_end(args);
	return (count);
}
