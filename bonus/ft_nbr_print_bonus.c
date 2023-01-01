/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2023/01/02 01:01:33 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_put_plus_space_num(t_flags flag, int num);

int	ft_nbr_print_bonus(va_list ap, t_flags flag)
{
	int		num;
	int		abs_digit;
	char	negative;
	int		result;

	num = va_arg(ap, int);
	abs_digit = ft_cal_abs_digit((long)num);
	negative = FALSE;
	if (num < 0)
		negative = TRUE;
	result = flag.width;
	if (flag.precision > abs_digit)
	{
		flag.zero = TRUE;
		if (flag.precision > flag.width)
			result = flag.precision + (negative || flag.plus || flag.sharp);
	}
	else if (flag.dot && flag.precision <= abs_digit)
		flag.zero = FALSE;
	if (abs_digit + negative >= result)
		result = abs_digit + negative + ft_put_plus_space_num(flag, num);
	else
		ft_nbr_flags(flag, num, abs_digit);
	return (result);
}

static int	ft_put_plus_space_num(t_flags flag, int num)
{
	int	result;

	result = 0;
	if (flag.plus && num >= 0)
	{
		ft_putchar_fd('+', 1);
		result++;
	}
	else if (flag.space && num >= 0)
	{
		ft_putchar_fd(' ', 1);
		result++;
	}
	ft_putnbr_fd((long)num, 1);
	return (result);
}
