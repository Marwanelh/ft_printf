/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:47:29 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 19:58:52 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

// Holds all the formatting flags parsed from the format string.
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;
	int	width;
	int	dot;
	int	precision;
	int	is_uppercase;
	int	specifier;
}		t_flags;

// Helper struct to hold calculated padding values.
typedef struct s_padding
{
	int	space;
	int	zero;
}		t_padding;

// --- Main Function (ft_printf.c) ---
int		ft_printf(const char *format, ...);

// --- Parsing Functions (ft_printf_parser.c) ---
int		parse_format_specifier(const char **format, va_list *args,
			t_flags *flags);
void	init_flags_struct(t_flags *flags);
void	parse_flags(const char **format, t_flags *flags);
void	parse_width(const char **format, va_list *args, t_flags *flags);
void	parse_precision(const char **format, va_list *args, t_flags *flags);

// --- Dispatch Function (ft_printf_dispatch.c) ---
int		dispatch_specifier(char specifier, va_list *args, t_flags *flags);

// --- Printing Functions ---
int		print_char_format(char c, t_flags *flags);
int		print_str_format(char *str, t_flags *flags);
int		print_int_format(int n, t_flags *flags);
int		print_uint_format(unsigned int n, t_flags *flags);
int		print_ptr_format(void *ptr, t_flags *flags);
int		print_hex_format(unsigned int n, t_flags *flags);

// --- Utility and Helper Functions ---
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr_base(unsigned long n, char *base);
void	calculate_padding(t_padding *pads, long nbr, int len, t_flags *flags);
int		print_hex_prefix(unsigned int n, t_flags *flags);
void	print_hex_digits(unsigned int n, t_flags *flags);
int		get_len_base(unsigned long n, int base_len);
int		print_padded_hex(unsigned int n, t_flags *flags, t_padding *pads);

#endif