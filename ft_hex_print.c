/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:39 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/25 19:21:46 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_print(unsigned int num, char *rule, int digit)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return (++digit);
	}
	digit++;
	digit = ft_hex_print(num / 16, rule, digit);
	ft_putchar_fd(rule[num % 16], 1);
	return (digit);
}

int	ft_low_hex_print(va_list ap)
{
	unsigned int	x;
	int				digit;

	x = va_arg(ap, unsigned int);
	digit = ft_hex_print(x, LOWERCASE_HEX, 0);
	return (digit);
}

int	ft_up_hex_print(va_list ap)
{
	unsigned int	x;
	int				digit;

	x = va_arg(ap, unsigned int);
	digit = ft_hex_print(x, UPPERCASE_HEX, 0);
	return (digit);
}
