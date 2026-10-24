/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:34:37 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/24 11:24:03 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_set_flag(char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else
		return (0);
	return (1);
}

static int	ft_read_width(const char *format, int *i, t_flags *flags)
{
	while (ft_isdigit(format[*i]))
	{
		if (flags->width > (INT_MAX - (format[*i] - '0')) / 10)
			return (-1);
		flags->width = flags->width * 10 + (format[*i] - '0');
		(*i)++;
	}
	return (0);
}

static int	ft_read_precision(const char *format, int *i, t_flags *flags)
{
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		while (ft_isdigit(format[*i]))
		{
			if (flags->precision > (INT_MAX - (format[*i] - '0')) / 10)
				return (-1);
			flags->precision = flags->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	return (0);
}

int	ft_read_flags_b(const char *format, int *i, t_flags *flags)
{
	int	ret;

	ft_bzero(flags, sizeof(t_flags));
	while (format[*i] && ft_set_flag(format[*i], flags))
		(*i)++;
	ret = ft_read_width(format, i, flags);
	if (ret < 0)
		return (-1);
	ret = ft_read_precision(format, i, flags);
	return (ret);
}
