/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:03:19 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/27 10:51:18 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_cal_digit(long long num)
{
	int	digit;

	digit = 0;
	if (num <= 0)
		digit++;
	while (num != 0)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}

int	ft_cal_hex_digit(unsigned int num, int digit)
{
	if (num < 16)
		return (++digit);
	digit++;
	digit = ft_cal_hex_digit(num / 16, digit);
	return (digit);
}
