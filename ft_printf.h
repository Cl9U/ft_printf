/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:30:00 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/25 09:44:13 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef int	(*t_conv)(va_list *args);

typedef struct s_parse
{
	char	spec;
	t_conv	func;
}	t_parse;

int		ft_printf(const char *format, ...);
int		ft_parse(char spec, va_list *args);

int		ft_print_char(va_list *args);
int		ft_print_str(va_list *args);
int		ft_print_ptr(va_list *args);
int		ft_print_nbr(va_list *args);
int		ft_print_unsigned(va_list *args);
int		ft_print_hex_low(va_list *args);
int		ft_print_hex_up(va_list *args);
int		ft_print_percent(va_list *args);

int		ft_printchar_count(unsigned char c);
char	*ft_utoa(unsigned long value, const char *base, unsigned long blen);

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif