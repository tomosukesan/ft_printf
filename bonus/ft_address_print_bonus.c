/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_print_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 15:53:26 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_put_address(uintptr_t num, char *rule, int digit);
static void	ft_address_adapt_width(t_flags flag, uintptr_t	p, int digit);

int	ft_address_print_bonus(va_list ap, t_flags flag)
{
	uintptr_t	p;
	int			result;
	int			digit;

	p = va_arg(ap, uintptr_t);
	digit = ft_cal_hex_digit(p);
	flag.width -= 2;
	if (digit >= flag.width)
	{
		result = digit;
		ft_putstr_fd("0x", 1);
		ft_put_address(p, LOWERCASE_HEX, digit);
	}
	else
	{
		result = flag.width;
		flag.width -= digit;
		ft_address_adapt_width(flag, p, digit);
	}
	return (result + 2);
}

static int	ft_put_address(uintptr_t num, char *rule, int digit)
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

static void	ft_address_adapt_width(t_flags flag, uintptr_t	p, int digit)
{
	if (flag.minus)
	{
		ft_putstr_fd("0x", 1);
		ft_put_address(p, LOWERCASE_HEX, digit);
		while (flag.width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flag.width-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_put_address(p, LOWERCASE_HEX, digit);
	}
}
