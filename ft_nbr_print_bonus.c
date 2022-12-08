/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:10:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:41:47 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static void	adapt_flags_with_minus(int n, int abs_dig, t_flags flag, int width);
static void	adapt_flags(int n, int abs_dig, t_flags flag, int width);
static int	ft_cal_zero_count(t_flags flag, int abs_dig, int width);
static int	ft_cal_empty_count(t_flags flag, int abs_dig, int width, int z_cnt);

void	ft_nbr_flags(t_flags flag, int num, int abs_dig, int width)
{
	if (flag.minus)
		adapt_flags_with_minus(num, abs_dig, flag, width);
	else
		adapt_flags(num, abs_dig, flag, width);
}

static void	adapt_flags_with_minus(int n, int abs_dig, t_flags flag, int width)
{
	if (flag.space && n >= 0)
	{
		ft_putchar_fd(' ', 1);
		width--;
	}
	else if (flag.plus && n >= 0)
	{
		ft_putchar_fd('+', 1);
		width--;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(n * -1, 1, abs_dig);
		width--;
	}
	else
		ft_putnbr_fd(n, 1, abs_dig);
	width -= abs_dig;
	while (width--)
		ft_putchar_fd(' ', 1);
}

void	adapt_flags(int n, int abs_dig, t_flags flag, int width)
{
	int	zero_count;
	int	empty_count;

	zero_count = ft_cal_zero_count(flag, abs_dig, width);
	empty_count = ft_cal_empty_count(flag, abs_dig, width, zero_count);
	if (flag.width || flag.precision)
	{
		if ((n >= 0 && (flag.plus || flag.space)) || n < 0)
		{
			empty_count -= 1;
			if (empty_count < 0)
				zero_count--;
		}
		while (empty_count-- > 0)
			ft_putchar_fd(' ', 1);
	}
	ft_nbr_put_flags(flag, n, zero_count);
	if (n < 0)
		ft_putnbr_fd(n * -1, 1, abs_dig);
	else
		ft_putnbr_fd(n, 1, abs_dig);
}

static int	ft_cal_zero_count(t_flags flag, int abs_dig, int width)
{
	int	zero_count;

	zero_count = 0;
	if (flag.precision > abs_dig)
		zero_count = flag.precision - abs_dig;
	else if (flag.zero && width > abs_dig)
		zero_count = flag.width - abs_dig;
	return (zero_count);
}

static int	ft_cal_empty_count(t_flags flag, int abs_dig, int width, int z_cnt)
{
	int	empty_count;

	empty_count = 0;
	if (flag.width)
		empty_count = flag.width - abs_dig;
	if (flag.zero)
		empty_count -= z_cnt;
	if (flag.precision > abs_dig)
		empty_count = width - flag.precision;
	return (empty_count);
}
