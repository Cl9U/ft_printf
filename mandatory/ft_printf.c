/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:29:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/21 23:20:27 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_step(const char *format, int *i, va_list *args)
{
	int	ret;

	if (format[*i] == '%')
	{
		if (format[*i + 1])
		{
			ret = ft_parse(format[*i + 1], args);
			*i += 2;
		}
		else
		{
			ret = -1;
			(*i)++;
		}
	}
	else
	{
		ret = ft_printchar_count(format[*i]);
		(*i)++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		ret;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		ret = ft_step(format, &i, &args);
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
