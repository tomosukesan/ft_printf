/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/08 14:58:20 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_decimal_flag(unsigned int n, int digit, t_flags flag, int width);
static void	ft_blank_handle(unsigned int n, int e_cnt, int z_cnt, t_flags flag);
static void	ft_put_uinbr_fd(unsigned int n, int fd, int digit);

int	ft_decimal_print_bonus(const char **argv, va_list ap, t_flags flag)
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
	if (digit >= result)
	{
		result = digit;
		ft_put_uinbr_fd(num, 1, digit);
	}
	else if (digit < result)
		ft_decimal_flag(num, digit, flag, result);
	argv++;
	return (result);
}

static void	ft_decimal_flag(unsigned int n, int digit, t_flags flag, int width)
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
	ft_blank_handle(n, empty_count, zero_count, flag);
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

static void	ft_put_uinbr_fd(unsigned int n, int fd, int digit)
{
	long long	devisor;
	long long	tmp;

	devisor = 1;
	tmp = (long long)n;
	while (n >= 10)
	{
		devisor *= 10;
		n /= 10;
		digit++;
	}
	while (devisor)
	{
		ft_putchar_fd((tmp / devisor) + '0', fd);
		tmp %= devisor;
		devisor /= 10;
	}
}