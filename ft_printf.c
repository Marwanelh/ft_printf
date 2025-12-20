/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:47:23 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 20:13:58 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// The main entry point of the library.
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init_flags_struct(&flags);
			count += parse_format_specifier(&format, &args, &flags);
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
