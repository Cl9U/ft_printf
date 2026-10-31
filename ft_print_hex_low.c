/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:05 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/31 17:49:17 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low(va_list *args)
{
	int		ret;
	char	*str;

	str = ft_utoa(va_arg(*args, unsigned int), "0123456789abcdef", 16);
	if (!str)
		return (-1);
	ret = ft_write_all(str, ft_strlen(str));
	free(str);
	return (ret);
}
