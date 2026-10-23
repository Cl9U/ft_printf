/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:34:36 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:36:08 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_b(char spec, va_list *args, t_flags *flags)
{
	int						i;
	static const t_parse	table[] = {
	{'c', ft_print_char_b},
	{'s', ft_print_str_b},
	{'p', ft_print_ptr_b},
	{'d', ft_print_nbr_b},
	{'i', ft_print_nbr_b},
	{'u', ft_print_unsigned_b},
	{'x', ft_print_hex_low_b},
	{'X', ft_print_hex_up_b},
	{'%', ft_print_percent_b},
	{0, NULL}
	};

	i = 0;
	while (table[i].spec)
	{
		if (table[i].spec == spec)
			return (table[i].func(args, flags));
		i++;
	}
	return (0);
}
