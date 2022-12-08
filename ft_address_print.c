/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:47:07 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_put_address(uintptr_t num, char *rule, int digit);

int	ft_address_print(const char **argv, va_list ap, t_flags flag)
{
	uintptr_t	p;
	int			result;
	int			digit;

	p = va_arg(ap, uintptr_t);
	result = 0;
	digit = ft_cal_hex_digit(p);
	flag.width -= 2;
	if (digit >= flag.width)
	{
		result = digit;
		ft_putstr_fd("0x", 1);
		ft_put_address(p, LOWERCASE_HEX, digit);
	}
	else if (digit < flag.width)
	{
		result = flag.width;
		flag.width -= digit;
		ft_address_blank_handle(flag, p, digit);
	}
	argv++;
	return (result + 2);
}

int	ft_put_address(uintptr_t num, char *rule, int digit)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return (++digit);
	}
	digit++;
	digit = ft_put_address(num / 16, rule, digit);
	ft_putchar_fd(rule[num % 16], 1);
	return (digit);
}
