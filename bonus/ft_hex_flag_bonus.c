/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/24 00:58:17 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_cal_zero_count(t_flags flag, int digit, int *width);
static int	ft_adapt_minus(unsigned int x, int width, t_flags flag, char *rule);
static int	ft_adapt_flags(unsigned int x, int width, t_flags flag, char *rule);

int	ft_hex_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	int	result;
	int	digit;

	digit = ft_cal_hex_digit(x);
	if (flag.minus)
		result = ft_adapt_minus(x, width, flag, rule);
	else
		result = ft_adapt_flags(x, width, flag, rule);
	if ((flag.sharp && x != 0) && width < digit + 2)
		result = digit + 2;
	return (result);
}

static int	ft_adapt_minus(unsigned int x, int width, t_flags flag, char *rule)
{
	int	result;
	int	digit;
	int	zero_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero_count(flag, digit, &width);
	result = width;
	ft_hex_prefix(x, flag, rule);
	while (zero_count-- > 0)
		ft_putchar_fd('0', 1);
	ft_hex_print(x, rule);
	width -= digit;
	while (width-- > 0)
		ft_putchar_fd(' ', 1);
	return (result);
}

static int	ft_adapt_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	int	digit;
	int	zero_count;
	int	empty_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero_count(flag, digit, &width);
	empty_count = width - zero_count - digit - (flag.sharp * 2);
	while (empty_count-- > 0)
		ft_putchar_fd(' ', 1);
	ft_hex_prefix(x, flag, rule);
	while (zero_count-- > 0)
		ft_putchar_fd('0', 1);
	ft_hex_print(x, rule);
	return (width);
}

static int	ft_cal_zero_count(t_flags flag, int digit, int *width)
{
	int	zero_count;

	zero_count = 0;
	if (flag.precision > digit)
	{
		zero_count = flag.precision - digit;
		if (flag.sharp && flag.precision > flag.width)
			*width += 2;
	}
	else if (flag.zero && *width > digit)
	{
		zero_count = flag.width - digit;
		if (flag.sharp)
			zero_count -= 2;
	}
	return (zero_count);
}
