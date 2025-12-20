/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:47:09 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:51:31 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Parses the '-', '0', '+', ' ', and '#' flags from the format string.
void	parse_flags(const char **format, t_flags *flags)
{
	while (ft_strchr("-0+ #", **format))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '#')
			flags->hash = 1;
		(*format)++;
	}
}

// Parses the width specifier, including the '*' for variable width.
void	parse_width(const char **format, va_list *args, t_flags *flags)
{
	if (ft_isdigit(**format))
	{
		flags->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		flags->width = va_arg(*args, int);
		(*format)++;
	}
}

// Parses the precision specifier ('.'),including the'*'for variable precision.
void	parse_precision(const char **format, va_list *args, t_flags *flags)
{
	if (**format == '.')
	{
		flags->dot = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			flags->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			flags->precision = va_arg(*args, int);
			(*format)++;
		}
	}
}

// Initializes the flags struct to default values before parsing.
void	init_flags_struct(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->is_uppercase = 0;
	flags->specifier = 0;
}

// The main parsing driver that calls other parsing and dispatching functions.
int	parse_format_specifier(const char **format, va_list *args,
	t_flags *flags)
{
	int	count;

	(*format)++;
	parse_flags(format, flags);
	parse_width(format, args, flags);
	parse_precision(format, args, flags);
	count = dispatch_specifier(**format, args, flags);
	(*format)++;
	return (count);
}
