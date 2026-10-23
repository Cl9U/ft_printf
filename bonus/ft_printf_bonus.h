/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:30:00 by sfaraji           #+#    #+#             */
/*   Updated: 2026/10/23 11:28:27 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	dot;
	int	precision;
}	t_flags;

typedef int	(*t_conv)(va_list *args, t_flags *flags);

typedef struct s_parse
{
	char	spec;
	t_conv	func;
}	t_parse;

int		ft_printf(const char *format, ...);
int		ft_parse_b(char spec, va_list *args, t_flags *flags);

int		ft_print_char_b(va_list *args, t_flags *flags);
int		ft_print_str_b(va_list *args, t_flags *flags);
int		ft_print_ptr_b(va_list *args, t_flags *flags);
int		ft_print_nbr_b(va_list *args, t_flags *flags);
int		ft_print_unsigned_b(va_list *args, t_flags *flags);
int		ft_print_hex_low_b(va_list *args, t_flags *flags);
int		ft_print_hex_up_b(va_list *args, t_flags *flags);
int		ft_print_percent_b(va_list *args, t_flags *flags);

int		ft_printchar_count_b(unsigned char c);
char	*ft_utoa_b(unsigned long value, const char *base, unsigned long blen);

#endif