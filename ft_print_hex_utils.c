/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:49 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:46:52 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Helper that manages the order of printing for hexadecimal numbers.
int	print_padded_hex(unsigned int n, t_flags *flags, t_padding *pads)
{
	int	count;

	count = 0;
	if (!flags->minus)
		while (pads->space-- > 0)
			count += ft_putchar(' ');
	count += print_hex_prefix(n, flags);
	while (pads->zero-- > 0)
		count += ft_putchar('0');
	if (!(flags->dot && flags->precision == 0 && n == 0))
		print_hex_digits(n, flags);
	if (flags->minus)
		while (pads->space-- > 0)
			count += ft_putchar(' ');
	return (count);
}

// Helper to print the "0x" or "0X" prefix for the '#' flag.
int	print_hex_prefix(unsigned int n, t_flags *flags)
{
	if (flags->hash && n != 0)
	{
		if (flags->is_uppercase)
			return (ft_putstr("0X"));
		else
			return (ft_putstr("0x"));
	}
	return (0);
}

// Helper to print the hexadecimal digits using the correct character case.
void	print_hex_digits(unsigned int n, t_flags *flags)
{
	if (flags->is_uppercase)
		ft_putnbr_base(n, "0123456789ABCDEF");
	else
		ft_putnbr_base(n, "0123456789abcdef");
}
