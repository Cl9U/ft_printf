/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:34:36 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/30 14:14:25 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	ft_parse(char spec)
{
	int						i;
	static const t_parse	table[] = {
	{'c', ft_print_char},
	{'s', ft_print_str},
	{'p', ft_print_ptr},
	{'d', ft_print_nbr},
	{'i', ft_print_nbr},
	{'u', ft_print_unsigned},
	{'x', ft_print_hex_low},
	{'X', ft_print_hex_up},
	{'%', ft_print_percent},
	{0, NULL}
	};

	i = 0;
	while (table[i].spec)
	{
		if (table[i].spec == spec)
			return (table[i].func);
		i++;
	}
	return (0);
}
