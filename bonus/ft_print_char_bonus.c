/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:30:02 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/24 11:49:49 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char_b(va_list *args, t_flags *flags)
{
	int	ret;

	(void)flags;
	ret = ft_printchar_count_b(va_arg(*args, int));
	return (ret);
}
