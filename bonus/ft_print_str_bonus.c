/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:54:51 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:52:23 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_str_b(va_list *args, t_flags *flags)
{
	int		ret;
	char	*str;
	(void)flags;

	str = va_arg(*args, char *);
	if (str == NULL)
		ret = write(1, "(null)", 6);
	else
		ret = write(1, str, ft_strlen(str));
	return (ret);
}
