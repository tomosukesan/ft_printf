/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:05:13 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/06 22:31:54 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_blank_handle(unsigned int n, int e_cnt, int z_cnt, t_flags flag);

void	ft_decimal_flags(unsigned int num, int digit, t_flags flag, int width)
{
	int	zero_count;
	int	empty_count;

	zero_count = 0;
	empty_count = 0;
	if (flag.width > digit)
		empty_count = flag.width - digit;
	if (flag.precision > digit)
	{
		zero_count = flag.precision - digit;
		empty_count = width - zero_count - digit;
	}
	else if (flag.zero && width > digit)
	{
		zero_count = flag.width - digit;
		empty_count = 0;
	}
	ft_blank_handle(num, empty_count, zero_count, flag);
}

static void	ft_blank_handle(unsigned int n, int e_cnt, int z_cnt, t_flags flag)
{
	int	digit;

	digit = ft_cal_abs_digit(n);
	if (flag.minus)
	{
		ft_put_uinbr_fd(n, 1, digit);
		while (e_cnt-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (e_cnt-- > 0)
			ft_putchar_fd(' ', 1);
		while (flag.zero && z_cnt-- > 0)
			ft_putchar_fd('0', 1);
		ft_put_uinbr_fd(n, 1, digit);
	}
}
