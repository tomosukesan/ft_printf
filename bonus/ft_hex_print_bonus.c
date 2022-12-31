/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 21:57:04 by ttachi           ###   ########.fr       */
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

int	ft_hex_process(va_list ap, char *rule, t_flags flag)
{
	unsigned int	x;
	int				digit;
	int				result;

	x = va_arg(ap, unsigned int);
	if (x == 0)
		flag.sharp = FALSE;
	digit = ft_cal_hex_digit((unsigned long)x);
	result = flag.width;
	if (flag.precision > digit)
	{
		flag.zero = TRUE;
		if (flag.precision > flag.width)
			result = flag.precision;
	}
	else if (flag.precision <= digit && flag.dot)
		flag.zero = FALSE;
	if (digit >= result)
	{
		result = digit + ft_hex_prefix(x, flag, rule) + flag.sharp;
		ft_hex_print(x, rule);
	}
	else
		result = ft_hex_flags(x, result, flag, rule);
	return (result);
}
