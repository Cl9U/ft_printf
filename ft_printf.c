/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:29:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/30 14:15:56 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_step(const char *format, int *i, va_list *args, int *bad)
{
	t_conv	conv;
	int		ret;
 
	if (format[*i] != '%')
		return (ft_printchar_count(format[(*i)++]));
	if (!format[*i + 1])
	{
		ret = -1;
		if (*bad)
			ret = ft_printchar_count('%');
		(*i)++;
		return (ret);
	}
	conv = ft_parse(format[*i + 1]);
	if (conv)
		ret = conv(args);
	else
	{
		*bad = 1;
		ret = write(1, format + *i, 2);
	}
	*i += 2;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		bad;
	int		count;
	int		ret;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	bad = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		ret = ft_step(format, &i, &args, &bad);
		if (ret < 0)
		{
			count = -1;
			break ;
		}
		count += ret;
	}
	va_end(args);
	return (count);
}
