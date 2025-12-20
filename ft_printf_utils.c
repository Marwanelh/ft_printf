/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:47:14 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:47:20 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Writes a single character to the standard output and returns 1.
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// Writes a string to the standard output and returns its length.
int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

// Prints an unsigned long number in a given base (e.g., base 10 or 16).
void	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
}

// Computes the required space and zero padding based on flags.
void	calculate_padding(t_padding *pads, long nbr, int len, t_flags *flags)
{
	int	is_negative;

	is_negative = (nbr < 0);
	pads->zero = 0;
	pads->space = 0;
	if (flags->dot && flags->precision > len - is_negative)
		pads->zero = flags->precision - (len - is_negative);
	pads->space = flags->width - (pads->zero + len);
	if ((flags->plus || flags->space) && !is_negative)
		pads->space--;
	if (flags->zero && !flags->minus && !flags->dot)
	{
		pads->zero += pads->space;
		pads->space = 0;
	}
}
