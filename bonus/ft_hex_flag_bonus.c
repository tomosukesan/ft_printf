/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/19 20:47:08 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_cal_zero_count(t_flags flag, int digit, int width);
static void	ft_adapt_minus(unsigned int x, int width, t_flags flag, char *rule);
static void	ft_adapt_flags(unsigned int x, int width, t_flags flag, char *rule);

void	ft_hex_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	if (flag.minus)
		ft_adapt_minus(x, width, flag, rule);
	else
		ft_adapt_flags(x, width, flag, rule);
}

static int	ft_cal_zero_count(t_flags flag, int digit, int width)
{
	int	zero_count;

	zero_count = 0;
	if (flag.precision > digit)
		zero_count = flag.precision - digit;
	else if (flag.zero && width > digit)
		zero_count = flag.width - digit;
	return (zero_count);
}

static void	ft_adapt_minus(unsigned int x, int width, t_flags flag, char *rule)
{
	int	digit;
	int	zero_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero_count(flag, digit, width);
	if (flag.sharp && x != 0)
		width = width + ft_hex_print_prefix(rule) - 2;
	while (zero_count-- > 0)
		ft_putchar_fd('0', 1);
	ft_hex_print(x, rule);
	width -= digit;
	while (width-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_adapt_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	int	digit;
	int	empty_count;
	int	zero_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero_count(flag, digit, width);
	empty_count = width - zero_count - digit - (flag.sharp * 2);
	while (empty_count-- > 0)
		ft_putchar_fd(' ', 1);
	if (flag.sharp && x != 0)
		zero_count += ft_hex_print_prefix(rule) - 2 + (flag.dot * 2);
	while (zero_count-- > 0)
		ft_putchar_fd('0', 1);
	ft_hex_print(x, rule);
}
