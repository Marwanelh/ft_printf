/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:55 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:49:52 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// (static) Helper to recursively print a long integer to standard output.
static void	putlong_nbr(long n)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n >= 10)
	{
		putlong_nbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

// (static) Helper to count the number of digits in a base-10 number.
static int	getnum_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// (static) Helper to print the correct sign ('+', '-', or space) for a number.
static int	print_sign(long nbr, t_flags *flags)
{
	if (nbr < 0)
		return (ft_putchar('-'));
	if (flags->plus)
		return (ft_putchar('+'));
	if (flags->space)
		return (ft_putchar(' '));
	return (0);
}

// Handles the printing and formatting for '%d' and '%i' (signed integers).
int	print_int_format(int n, t_flags *flags)
{
	long		nbr;
	int			len;
	int			count;
	t_padding	pads;

	nbr = n;
	count = 0;
	len = getnum_len(nbr);
	if (flags->dot && flags->precision == 0 && nbr == 0)
		len = 0;
	calculate_padding(&pads, nbr, len, flags);
	if (!flags->minus)
		while (pads.space-- > 0)
			count += ft_putchar(' ');
	count += print_sign(nbr, flags);
	while (pads.zero-- > 0)
		count += ft_putchar('0');
	if (len > 0)
		putlong_nbr(nbr);
	if (flags->minus)
		while (pads.space-- > 0)
			count += ft_putchar(' ');
	return (count + len);
}

// Helper to manage the order of printing spaces, signs, and digits.
int	print_padded_int(long nbr, t_flags *flags, t_padding *pads)
{
	int	count;

	count = 0;
	if (!flags->minus)
		while (pads->space-- > 0)
			count += ft_putchar(' ');
	count += print_sign(nbr, flags);
	while (pads->zero-- > 0)
		count += ft_putchar('0');
	if (!(flags->dot && flags->precision == 0 && nbr == 0))
		putlong_nbr(nbr);
	if (flags->minus)
		while (pads->space-- > 0)
			count += ft_putchar(' ');
	return (count);
}
