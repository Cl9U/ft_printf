/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:29:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:37:46 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_step(const char *format, int *i, va_list *args, t_flags *flags)
{
	int	ret;

	if (format[*i] == '%')
	{
		if (format[*i + 1])
		{
			ret = ft_parse_b(format[*i + 1], args, flags);
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
	t_flags flags;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		ret = ft_step(format, &i, &args, &flags);
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
