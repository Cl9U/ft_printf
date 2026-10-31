/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:17 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/31 17:51:52 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list *args)
{
	int				ret;
	int				fret;
	char			*str;
	unsigned long	arg;

	arg = (unsigned long)va_arg(*args, void *);
	if (!arg)
	{
		ret = ft_write_all("(nil)", 5);
		return (ret);
	}
	str = ft_utoa(arg, "0123456789abcdef", 16);
	if (!str)
		return (-1);
	fret = ft_write_all("0x", 2);
	ret = fret;
	if (ret >= 0)
	{
		ret = ft_write_all(str, ft_strlen(str));
		if (ret >= 0)
			ret += fret;
	}
	free(str);
	return (ret);
}
