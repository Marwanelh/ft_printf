/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:47:03 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:48:57 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Calls the correct printing function based on the specifier (c, s, d, etc.).
int	dispatch_specifier(char specifier, va_list *args, t_flags *flags)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char_format(va_arg(*args, int), flags);
	else if (specifier == 's')
		count += print_str_format(va_arg(*args, char *), flags);
	else if (specifier == 'p')
		count += print_ptr_format(va_arg(*args, void *), flags);
	else if (specifier == 'd' || specifier == 'i')
		count += print_int_format(va_arg(*args, int), flags);
	else if (specifier == 'u')
		count += print_uint_format(va_arg(*args, unsigned int), flags);
	else if (specifier == 'x' || specifier == 'X')
	{
		if (specifier == 'X')
			flags->is_uppercase = 1;
		count += print_hex_format(va_arg(*args, unsigned int), flags);
	}
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}
