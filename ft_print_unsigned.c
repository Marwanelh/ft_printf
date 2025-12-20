/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:46:59 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/24 18:50:51 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Handles the printing and formatting for the '%u' specifier.
int	print_uint_format(unsigned int n, t_flags *flags)
{
	int			count;
	int			len;
	t_padding	pads;

	count = 0;
	len = get_len_base(n, 10);
	if (flags->dot && flags->precision == 0 && n == 0)
		len = 0;
	calculate_padding(&pads, 1, len, flags);
	if (!flags->minus)
		while (pads.space-- > 0)
			count += ft_putchar(' ');
	while (pads.zero-- > 0)
		count += ft_putchar('0');
	if (len > 0)
		ft_putnbr_base(n, "0123456789");
	if (flags->minus)
		while (pads.space-- > 0)
			count += ft_putchar(' ');
	return (count + len);
}
