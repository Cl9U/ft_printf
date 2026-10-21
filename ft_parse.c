/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:34:36 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/21 13:26:55 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_parse	g_table[] = 
{
	{'c', ft_print_char},
	//{'s', ft_print_str},
	//{'p', ft_print_ptr},
	//{'d', ft_print_nbr},
	//{'i', ft_print_nbr},
	//{'u', ft_print_unsigned},
	//{'x', ft_print_hex_low},
	//{'X', ft_print_hex_up},
	{'%', ft_print_percent},
	{0, NULL}
};

int	ft_parse(char spec, va_list *args)
{
	int	i;

	i = 0;
	while (g_table[i].spec)
	{
		if (g_table[i].spec == spec)
			return (g_table[i].func(args));
		i++;
	}
	return (0);
}