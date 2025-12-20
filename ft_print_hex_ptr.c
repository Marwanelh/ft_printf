/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:45 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:46:47 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// (static) Helper to count the number of digits in a number of any base.
int	get_len_base(unsigned long n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

// (static) Helper to print "(nil)" with the correct padding for a NULL pointer.
static int	print_padded_nil(t_flags *flags)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	len = ft_strlen("(nil)");
	padding = flags->width - len;
	if (!flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	count += ft_putstr("(nil)");
	if (flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	return (count);
}

// (static) Helper to print a valid memory address with padding.
static int	print_padded_addr(unsigned long addr, t_flags *flags)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	len = get_len_base(addr, 16) + 2;
	padding = 0;
	if (flags->width > len)
		padding = flags->width - len;
	if (!flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	ft_putstr("0x");
	ft_putnbr_base(addr, "0123456789abcdef");
	if (flags->minus)
		while (padding-- > 0)
			count += ft_putchar(' ');
	return (count + len);
}

// Handles the printing and formatting for the '%p' (pointer) specifier.
int	print_ptr_format(void *ptr, t_flags *flags)
{
	if (!ptr)
		return (print_padded_nil(flags));
	else
		return (print_padded_addr((unsigned long)ptr, flags));
}

// Handles the printing and formatting for '%x' and '%X' (hexadecimal).
int	print_hex_format(unsigned int n, t_flags *flags)
{
	int			len;
	int			count;
	t_padding	pads;

	len = get_len_base(n, 16);
	if (flags->dot && flags->precision == 0 && n == 0)
		len = 0;
	if (flags->is_uppercase)
		flags->specifier = 'X';
	else
		flags->specifier = 'x';
	calculate_padding(&pads, n, len, flags);
	count = print_padded_hex(n, flags, &pads);
	return (count + len);
}
