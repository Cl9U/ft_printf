/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:42:33 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/31 17:59:48 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_all(const char *s, size_t len)
{
	size_t	done;
	ssize_t	ret;

	done = 0;
	while (done < len)
	{
		ret = write(1, s + done, len - done);
		if (ret <= 0)
			return (-1);
		done += ret;
	}
	return ((int)done);
}
