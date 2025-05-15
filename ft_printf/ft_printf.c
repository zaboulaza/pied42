/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:15:22 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/14 15:48:20 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_op(char format, va_list ap)
{
	int				count_total;
	unsigned long	xcs;

	count_total = 0;
	if (format == 'c')
		count_total += ft_putchar2(va_arg(ap, int));
	if (format == '%')
		count_total += ft_putchar2('%');
	if (format == 's')
		count_total += ft_putstr2(va_arg(ap, char *));
	if (format == 'd' || format == 'i')
		count_total += ft_putnbr2(va_arg(ap, int));
	if (format == 'p')
	{
		xcs = va_arg(ap, unsigned long);
		if (xcs != 0)
			count_total += ft_putstr2("0x");
		count_total += ft_putnbr_hexa_pointer(xcs, xcs == 0);
	}
	if (format == 'u')
		count_total += ft_putnbr_unsigned(va_arg(ap, unsigned));
	if (format == 'x' || format == 'X')
		count_total += ft_putnbr_hexa(format, va_arg(ap, unsigned int));
	return (count_total);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counttotal;

	counttotal = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] && format[i] != '\0')
	{
		if (format[i] != '%')
			counttotal += ft_putchar2(format[i]);
		if (format[i] == '%')
		{
			i++;
			counttotal += do_op(format[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (counttotal);
}

// int main()
// {
// 	char *ptr = "oe";

// 	printf("%s", ptr);
// 	ft_printf("%s", ptr);
// }