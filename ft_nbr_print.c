/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2023/01/01 15:23:28 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_fd(int num, int digit);

int	ft_nbr_print(va_list ap)
{
	int	d;
	int	digit;

	d = va_arg(ap, int);
	digit = ft_putnbr_fd(d, 1);
	return (digit);
}

static int	ft_putnbr_fd(int num, int digit)
{
	long	devisor;
	long	abs_num;

	devisor = 1;
	abs_num = (long long)num;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		abs_num *= -1;
		digit++;
	}
	while (num <= -10 || num >= 10)
	{
		devisor *= 10;
		num /= 10;
		digit++;
	}
	while (devisor)
	{
		ft_putchar_fd((abs_num / devisor) + '0', 1);
		abs_num %= devisor;
		devisor /= 10;
	}
	return (digit);
}
