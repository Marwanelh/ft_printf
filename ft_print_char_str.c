/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:33 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:51:07 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Handles the printing and formatting for the '%c' (character) specifier.
int	print_char_format(char c, t_flags *flags)
{
	int	count;
	int	padding;

	count = 0;
	padding = flags->width - 1;
	if (!flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	count += ft_putchar(c);
	if (flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	return (count);
}

// Handles the printing and formatting for the '%s' (string) specifier.
int	print_str_format(char *str, t_flags *flags)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	padding = flags->width - len;
	if (!flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	write(1, str, len);
	if (flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	return (count + len);
}
