/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:08 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/24 11:48:57 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_hex_up_b(va_list *args, t_flags *flags)
{
	int		ret;
	char	*str;

	(void)flags;
	str = ft_utoa_b(va_arg(*args, unsigned int), "0123456789ABCDEF", 16);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}
