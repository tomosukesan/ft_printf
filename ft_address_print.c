/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/04 22:48:04 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_put_hex(unsigned long long num, char *rule, int digit);

int	ft_address_print(const char **argv, va_list ap)
{
	unsigned long long	p;
	int					digit;

	p = va_arg(ap, unsigned long long);
	digit = ft_putstr_fd("0x", 1);
	digit += ft_put_hex(p, LOWERCASE_HEX, digit) - 1;
	argv++;
	return (digit);
}

static int	ft_put_hex(unsigned long long num, char *rule, int digit)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return (digit);
	}
	digit = ft_put_hex(num / 16, rule, digit) + 1;
	ft_putchar_fd(rule[num % 16], 1);
	return (digit);
}
