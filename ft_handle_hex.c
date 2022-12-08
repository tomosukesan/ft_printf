/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:07:44 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_hex_process_prefix(char *rule);

int	ft_handle_hex(const char **argv, va_list ap, char *rule, t_flags flag)
{
	unsigned int	x;
	int				digit;
	int				result;

	x = va_arg(ap, unsigned int);
	digit = ft_cal_hex_digit(x);
	result = flag.width;
	if (flag.precision > digit)
	{
		flag.zero = TRUE;
		if (flag.precision > flag.width)
			result = flag.precision;
	}
	if (digit >= result)
	{
		result = digit;
		if (flag.sharp && x != 0)
			result = result + ft_hex_process_prefix(rule) + 2;
		ft_hex_print(x, rule);
	}
	else if (digit < result)
		ft_hex_flags((unsigned int)x, result, flag, rule);
	argv++;
	return (result);
}

int	ft_hex_process_prefix(char *rule)
{
	if (rule[10] == 'a')
		ft_putstr_fd("0x", 1);
	else if (rule[10] == 'A')
		ft_putstr_fd("0X", 1);
	return (0);
}
