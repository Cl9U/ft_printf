/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:29 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/22 14:28:16 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(va_list *args)
{
	int		ret;
	char	*str;

	str = ft_utoa(va_arg(*args, unsigned int), "0123456789", 10);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}