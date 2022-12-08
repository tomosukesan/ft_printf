/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:41:26 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_nbr_print(const char **argv, va_list ap, t_flags flag)
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
			result = flag.precision + minus;
	}
	if (abs_digit + minus >= result)
		result = abs_digit + minus + \
					ft_adapt_space_plus(flag, num, abs_digit, minus);
	else if (abs_digit + minus < result)
		ft_nbr_flags(flag, num, abs_digit, result);
	argv++;
	return (result);
}
