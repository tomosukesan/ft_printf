/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/19 20:49:49 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	hex_left_align(unsigned int x, int digit, t_flags flag, char *rule);

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

int	ft_hex_print_prefix(char *rule)
{
	if (rule[10] == 'a')
		ft_putstr_fd("0x", 1);
	else if (rule[10] == 'A')
		ft_putstr_fd("0X", 1);
	return (0);
}

int	ft_hex_process(const char **argv, va_list ap, char *rule, t_flags flag)
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
	else if (flag.dot && flag.precision <= digit)
		flag.zero = FALSE;
	if (digit >= result)
		result = hex_left_align(x, digit, flag, rule);
	else if (digit < result)
		ft_hex_flags(x, result, flag, rule);
	argv++;
	return (result);
}

static int	hex_left_align(unsigned int x, int digit, t_flags flag, char *rule)
{
	int	result;

	result = digit;
	if (flag.sharp && x != 0)
		result = result + ft_hex_print_prefix(rule) + 2;
	ft_hex_print(x, rule);
	return (result);
}
