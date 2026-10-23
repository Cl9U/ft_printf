/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:55:11 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 10:16:11 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(va_list *args)
{
	int		ret;
	char	*num;

	num = ft_itoa(va_arg(*args, int));
	if (!num)
		return (-1);
	ret = write(1, num, ft_strlen(num));
	free(num);
	return (ret);
}
