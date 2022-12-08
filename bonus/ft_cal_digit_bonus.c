/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_digit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:03:19 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/08 14:17:39 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_cal_abs_digit(long long num)
{
	int					digit;
	unsigned long long	abs_num;

	digit = 0;
	if (num < 0)
		abs_num = num * -1;
	else
		abs_num = num;
	if (abs_num == 0)
		digit++;
	while (abs_num != 0)
	{
		digit++;
		abs_num /= 10;
	}
	return (digit);
}

int	ft_cal_hex_digit(unsigned long num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		digit++;
	while (num != 0)
	{
		digit++;
		num /= 16;
	}
	return (digit);
}
