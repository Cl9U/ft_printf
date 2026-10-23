/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:11 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:52:36 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_nbr_b(va_list *args, t_flags *flags)
{
	int		ret;
	char	*num;
	(void)flags;

	num = ft_itoa(va_arg(*args, int));
	if (!num)
		return (-1);
	ret = write(1, num, ft_strlen(num));
	free(num);
	return (ret);
}
