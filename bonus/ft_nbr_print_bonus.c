/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/19 22:47:47 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_put_space_plus_num(t_flags flag, int num);

int	ft_nbr_print_bonus(const char **argv, va_list ap, t_flags flag)
{
	int	num;
	int	abs_digit;
	int	minus;
	int	result;

	num = va_arg(ap, int);
	abs_digit = ft_cal_abs_digit(num);
	minus = FALSE;
	if (num < 0)
		minus = TRUE;
	result = flag.width;
	if (flag.precision > abs_digit)
	{
		flag.zero = TRUE;
		if (flag.precision > flag.width)
			result = flag.precision + (minus || flag.plus || flag.sharp);
	}
	else if (flag.dot && flag.precision <= abs_digit)
		flag.zero = FALSE;
	if (abs_digit + minus >= result)
		result = abs_digit + minus + ft_put_space_plus_num(flag, num);
	else if (abs_digit + minus < result)
		ft_nbr_flags(flag, num, abs_digit, result);
	argv++;
	return (result);
}

static int	ft_put_space_plus_num(t_flags flag, int num)
{
	int	result;

	result = 0;
	if (flag.space && num >= 0)
	{
		ft_putchar_fd(' ', 1);
		result++;
	}
	else if (flag.plus && num >= 0)
	{
		ft_putchar_fd('+', 1);
		result++;
	}
	ft_putnbr_fd(num, 1);
	return (result);
}

void	ft_nbr_put_flags(t_flags flag, int n, int z_cnt)
{
	if (flag.space && n >= 0)
		ft_putchar_fd(' ', 1);
	else if (flag.plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (n < 0)
		ft_putchar_fd('-', 1);
	if (flag.zero)
		while (z_cnt-- > 0)
			ft_putchar_fd('0', 1);
}
