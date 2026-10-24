/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpad_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:34:22 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/24 11:54:46 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putpad_b(char c, int n)
{
	int	total;
	int	ret;

	total = 0;
	while (total < n)
	{
		ret = ft_printchar_count_b((unsigned char)c);
		if (ret < 0)
			return (-1);
		total++;
	}
	return (total);
}