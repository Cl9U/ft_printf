/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:54:51 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/22 11:02:59 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *args)
{
	int		ret;
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		ret = write(1, "(null)", 6);
	else
		ret = write(1, str, ft_strlen(str));
	return (ret);
}
