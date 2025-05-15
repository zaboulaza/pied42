/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:41:06 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/13 11:48:04 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar2(int c);
int	ft_putstr2(char *str);
int	count_int(long nb);
int	ft_putnbr2(int nb);
int	ft_putnbr_unsigned(int nb);
int	count_unsigned(int nb);
int	count_hexa(unsigned int nb);
int	ft_putnbr_hexa(char c, unsigned int nb);
int	ft_putchar_maj_min(int a, char c);
int	ft_putnbr_hexa_pointer(unsigned long nb, int is_null);
int	count_hexa_pointer(unsigned long nb);

#endif
