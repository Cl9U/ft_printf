/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:28:19 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:28:05 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_ctd(unsigned long n, unsigned long blen)
{
	int	dlen;

	dlen = 1;
	while (n >= blen)
	{
		n /= blen;
		dlen++;
	}
	return (dlen);
}

char	*ft_utoa_b(unsigned long value, const char *base, unsigned long blen)
{
	char			*str;
	int				dlen;
	unsigned long	n;

	n = value;
	dlen = ft_ctd(n, blen);
	str = malloc((dlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[dlen] = '\0';
	while (dlen > 0)
	{
		str[dlen - 1] = base[n % blen];
		n /= blen;
		dlen--;
	}
	return (str);
}
