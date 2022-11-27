/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/27 16:26:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>
static int	ft_put_hex(uintptr_t num, char *rule, int digit);

int	ft_address_print(const char **argv, va_list ap, t_flags flag)
{
	uintptr_t	p;
	int			result;
	int			digit;

	p = va_arg(ap, uintptr_t);
	result = 0;
	digit = 0;
	digit = ft_cal_hex_digit(p, digit);
	flag.width -= 2;
	if (digit >= flag.width)
	{
		result = digit;
		ft_putstr_fd("0x", 1);
		ft_put_hex(p, LOWERCASE_HEX, digit);
	}
	else if (digit < flag.width)
	{
		result = flag.width;
		flag.width -= digit;
		if (flag.minus)
		{
			ft_putstr_fd("0x", 1);
			ft_put_hex(p, LOWERCASE_HEX, digit);
			while (flag.width--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flag.width--)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd("0x", 1);
			ft_put_hex(p, LOWERCASE_HEX, digit);
		}
	}
	argv++;
	return (result + 2);
}

static int	ft_put_hex(uintptr_t num, char *rule, int digit)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return (++digit);
	}
	digit++;
	digit = ft_put_hex(num / 16, rule, digit);
	ft_putchar_fd(rule[num % 16], 1);
	return (digit);
}
