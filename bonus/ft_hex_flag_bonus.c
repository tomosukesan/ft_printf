/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/08 19:59:49 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_cal_zero_count(t_flags flag, int digit, int width);
static int	ft_cal_empty_count(t_flags flag, int digit, int width, int z_cnt);
static void	ft_adapt_minus(t_flags flag, int width, unsigned int x, char *rule);

void	ft_hex_flags(unsigned int x, int width, t_flags flag, char *rule)
{
	int		digit;
	int		empty_count;
	int		zero_count;

	digit = ft_cal_hex_digit(x);
	zero_count = ft_cal_zero_count(flag, digit, width);
	empty_count = ft_cal_empty_count(flag, digit, width, zero_count);
	if (flag.minus)
		ft_adapt_minus(flag, width, x, rule);
	else
	{
		if (flag.zero && flag.precision > digit)
			zero_count = flag.precision - digit;
		empty_count = width - zero_count - digit - (flag.sharp * 2);
		while (empty_count--)
			ft_putchar_fd(' ', 1);
		if (flag.sharp && x != 0)
			ft_hex_print_prefix(rule);
		while (zero_count--)
			ft_putchar_fd('0', 1);
		ft_hex_print(x, rule);
	}
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

static int	ft_cal_empty_count(t_flags flag, int digit, int width, int z_cnt)
{
	int	empty_count;

	empty_count = 0;
	if (flag.precision > digit)
		empty_count = width - z_cnt - digit;
	return (empty_count);
}

static void	ft_adapt_minus(t_flags flag, int width, unsigned int x, char *rule)
{
	int	digit;

	digit = ft_cal_hex_digit(x);
	if (flag.sharp && x != 0)
		width = width + ft_hex_print_prefix(rule) - 2;
	ft_hex_print(x, rule);
	width -= digit;
	while (width--)
		ft_putchar_fd(' ', 1);
}
