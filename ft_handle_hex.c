/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/27 14:17:54 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hex(const char **argv, va_list ap, char *rule, t_flags flag)
{
	unsigned int	x;
	int				digit;
	int				result;
	char			c;

	digit = 0;
	x = va_arg(ap, unsigned int);
	digit = ft_cal_hex_digit(x, digit);
	result = 0;

	if (digit >= flag.width)
	{
		result = digit;
		if (flag.sharp)
		{
			if (rule[10] == 'a')
				ft_putstr_fd("0x", 1);
			else if (rule[10] == 'A')
				ft_putstr_fd("0X", 1);
		}
		ft_hex_print(x, rule, digit);
	}
	else if (digit < flag.width)
	{
		result = flag.width;
		flag.width -= digit;
		if (flag.sharp)
			flag.width -= 2;
		if (flag.minus)
		{
			if (flag.sharp)
			{
				if (rule[10] == 'a')
					ft_putstr_fd("0x", 1);
				else if (rule[10] == 'A')
					ft_putstr_fd("0X", 1);
			}
			ft_hex_print(x, rule, digit);
			while (flag.width--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (flag.zero)
				c = '0';
			while (flag.width--)
				ft_putchar_fd(c, 1);
			if (flag.sharp)
			{
				if (rule[10] == 'a')
					ft_putstr_fd("0x", 1);
				else if (rule[10] == 'A')
					ft_putstr_fd("0X", 1);
			}
			ft_hex_print(x, rule, digit);
		}
	}
	argv++;
	return (result);
}
