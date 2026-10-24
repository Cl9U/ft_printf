/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:29:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/24 11:43:45 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_percent(const char *format, int *i, va_list *args)
{
	t_flags	flags;
	int		ret;

	(*i)++;
	if (ft_read_flags_b(format, i, &flags) < 0)
		return (-1);
	if (!format[*i])
		return (-1);
	ret = ft_parse_b(format[*i], args, &flags);
	(*i)++;
	return (ret);
}

static int	ft_step(const char *format, int *i, va_list *args)
{
	int	ret;

	if (format[*i] == '%')
		ret = ft_percent(format, i, args);
	else
	{
		ret = ft_printchar_count_b(format[*i]);
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
