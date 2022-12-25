/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:10:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/08 12:35:15 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_cal_zero_empty(t_flags flag, int abs_dig, int width, int *z_cnt);
static void	ft_adapt_minus(t_flags flag, int num, int z_cnt, int e_cnt);
static void	ft_adapt_flags(t_flags flag, int num, int z_cnt, int e_cnt);
static void	ft_nbr_put_flags(t_flags flag, int n, int z_cnt);

void	ft_nbr_flags(t_flags flag, int num, int abs_dig, int width)
{
	int	zero_count;
	int	empty_count;

	zero_count = 0;
	empty_count = ft_cal_zero_empty(flag, abs_dig, width, &zero_count);
	if (flag.width || flag.precision)
	{
		if ((num >= 0 && (flag.plus || flag.space)) || num < 0)
		{
			empty_count -= 1;
			if (empty_count < 0)
				zero_count--;
		}
	}
	if (flag.minus)
		ft_adapt_minus(flag, num, zero_count, empty_count);
	else
		ft_adapt_flags(flag, num, zero_count, empty_count);
}

static int	ft_cal_zero_empty(t_flags flag, int abs_dig, int width, int *z_cnt)
{
	int	empty_count;

	if (flag.precision > abs_dig)
		*z_cnt = flag.precision - abs_dig;
	else if (flag.zero && width > abs_dig)
		*z_cnt = flag.width - abs_dig;
	empty_count = 0;
	if (flag.width)
		empty_count = flag.width - abs_dig;
	if (flag.zero)
		empty_count -= *z_cnt;
	if (flag.precision > abs_dig)
		empty_count = width - flag.precision;
	return (empty_count);
}

static void	ft_adapt_minus(t_flags flag, int num, int z_cnt, int e_cnt)
{
	ft_nbr_put_flags(flag, num, z_cnt);
	if (num < 0)
		ft_putnbr_fd(num * -1, 1);
	else
		ft_putnbr_fd(num, 1);
	while (e_cnt-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_adapt_flags(t_flags flag, int num, int z_cnt, int e_cnt)
{
	while (e_cnt-- > 0)
		ft_putchar_fd(' ', 1);
	ft_nbr_put_flags(flag, num, z_cnt);
	if (num < 0)
		ft_putnbr_fd(num * -1, 1);
	else
		ft_putnbr_fd(num, 1);
}

static void	ft_nbr_put_flags(t_flags flag, int n, int z_cnt)
{
	if (flag.plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (flag.space && n >= 0)
		ft_putchar_fd(' ', 1);
	else if (n < 0)
		ft_putchar_fd('-', 1);
	if (flag.zero)
		while (z_cnt-- > 0)
			ft_putchar_fd('0', 1);
}
