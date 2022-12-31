/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/28 19:27:54 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_cal_zero(t_flags flag, int digit, int *width);
static int	ft_adapt_minus(unsigned int x, int width, t_flags flag, char *rule);
static int	ft_adapt_flags(unsigned int x, int width, t_flags flag, char *rule);

int	ft_hex_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	int	result;

	if (flag.minus)
		result = ft_adapt_minus(x, width, flag, rule);
	else
		result = ft_adapt_flags(x, width, flag, rule);
	return (result);
}

static int	ft_adapt_minus(unsigned int x, int width, t_flags flag, char *rule)
{
	int	digit;
	int	zero_count;
	int	empty_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero(flag, digit, &width);
	empty_count = width - zero_count - digit;
	if (x != 0 && flag.sharp)
		empty_count -= 2;
	ft_hex_prefix(x, flag, rule);
	while (zero_count-- > 0)
		ft_putchar_fd('0', 1);
	ft_hex_print(x, rule);
	while (empty_count-- > 0)
		ft_putchar_fd(' ', 1);
	return (width);
}

static int	ft_adapt_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	int	digit;
	int	zero_count;
	int	empty_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero(flag, digit, &width);
	empty_count = width - zero_count - digit - flag.sharp;
	while (empty_count-- > 0)
		ft_putchar_fd(' ', 1);
	ft_hex_prefix(x, flag, rule);
	while (zero_count-- > 0)
		ft_putchar_fd('0', 1);
	ft_hex_print(x, rule);
	return (width);
}

static int	ft_cal_zero(t_flags flag, int digit, int *width)
{
	int	zero_count;

	zero_count = 0;
	if (flag.width >= flag.precision)
	{
		if (flag.precision >= digit)
			zero_count = flag.precision - digit;
		else
			if (flag.zero)
				zero_count = flag.width - digit - flag.sharp;
		if (flag.width < flag.precision + flag.sharp)
			*width = flag.precision + flag.sharp;
		else if (flag.width < digit + flag.sharp)
			*width = digit + flag.sharp;
	}
	else
	{
		zero_count = flag.precision - digit;
		*width += flag.sharp;
	}
	return (zero_count);
}
