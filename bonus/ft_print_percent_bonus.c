/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:14 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/24 11:49:10 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_percent_b(va_list *args, t_flags *flags)
{
	int	ret;

	(void)flags;
	(void)args;
	ret = ft_printchar_count_b('%');
	return (ret);
}
