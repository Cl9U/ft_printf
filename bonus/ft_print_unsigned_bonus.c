/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:29 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:52:44 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_unsigned_b(va_list *args, t_flags *flags)
{
	int		ret;
	char	*str;
	(void)flags;

	str = ft_utoa_b(va_arg(*args, unsigned int), "0123456789", 10);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}
