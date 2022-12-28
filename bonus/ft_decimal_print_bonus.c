/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/27 21:18:41 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	cnt_zero_empty(unsigned int n, int digit, t_flags flag);
static void	ft_adapt_flags(unsigned int n, int e_cnt, int z_cnt, t_flags flag);
static void	ft_put_uinbr_fd(unsigned int n, int fd, int digit);

int	ft_decimal_print_bonus(va_list ap, t_flags flag)
{
	unsigned int	num;
	int				digit;
	int				result;

	num = va_arg(ap, unsigned int);
	digit = ft_cal_abs_digit(num);
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
	{
		result = digit;
		ft_put_uinbr_fd(num, 1, digit);
	}
	else if (digit < result)
		cnt_zero_empty(num, digit, flag);
	return (result);
}

static void	cnt_zero_empty(unsigned int n, int digit, t_flags flag)
{
	int	zero_count;
	int	empty_count;

	zero_count = 0;
	empty_count = 0;
	if (flag.width >= flag.precision)
	{
		if (flag.precision > digit)
		{
			zero_count = flag.precision - digit;
			empty_count = flag.width - flag.precision;
		}
		else
		{
			empty_count = flag.width - digit;
			if (flag.zero)
			{
				zero_count = flag.width - digit;
				empty_count -= zero_count;
			}
		}
	}
	else
		zero_count = flag.precision - digit;
	ft_adapt_flags(n, empty_count, zero_count, flag);
}

static void	ft_adapt_flags(unsigned int n, int e_cnt, int z_cnt, t_flags flag)
{
	int	digit;

	digit = ft_cal_abs_digit(n);
	if (flag.minus)
	{
		while (flag.zero && z_cnt-- > 0)
			ft_putchar_fd('0', 1);
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

static void	ft_put_uinbr_fd(unsigned int n, int fd, int digit)
{
	unsigned int	devisor;
	unsigned int	tmp;

	devisor = 1;
	tmp = n;
	while (tmp >= 10)
	{
		devisor *= 10;
		tmp /= 10;
		digit++;
	}
	while (devisor)
	{
		ft_putchar_fd((n / devisor) + '0', fd);
		n %= devisor;
		devisor /= 10;
	}
}
