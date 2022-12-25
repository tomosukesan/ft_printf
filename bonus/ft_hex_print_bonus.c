/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/24 01:04:02 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_hex_print(unsigned int num, char *rule)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return ;
	}
	ft_hex_print(num / 16, rule);
	ft_putchar_fd(rule[num % 16], 1);
}

int	ft_hex_prefix(unsigned int x, t_flags flag, char *rule)
{
	if (flag.sharp && x != 0)
	{
		if (rule[10] == 'a')
			ft_putstr_fd("0x", 1);
		else if (rule[10] == 'A')
			ft_putstr_fd("0X", 1);
	}
	return (0);
}

int	ft_hex_process(const char **argv, va_list ap, char *rule, t_flags flag)
{
	unsigned int	x;
	int				dig;
	int				re;

	x = va_arg(ap, unsigned int);
	dig = ft_cal_hex_digit(x);
	re = flag.width;
	if (flag.precision > dig)
	{
		flag.zero = TRUE;
		if (flag.precision > flag.width)
			re = flag.precision;
	}
	else if (flag.precision <= dig && flag.dot)
		flag.zero = FALSE;
	if (dig >= re)
	{
		re = dig + ft_hex_prefix(x, flag, rule) + ((flag.sharp && x != 0) * 2);
		ft_hex_print(x, rule);
	}
	else if (dig < re)
		re = ft_hex_flags(x, re, flag, rule);
	argv++;
	return (re);
}
