/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:54:51 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/31 17:52:01 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *args)
{
	int		ret;
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		ret = ft_write_all("(null)", 6);
	else
		ret = ft_write_all(str, ft_strlen(str));
	return (ret);
}
