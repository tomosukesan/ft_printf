/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/22 10:38:01 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_fd(int num, int fd, int digit);

int	ft_nbr_print(const char **argv, va_list ap)
{
	int	digit;
	int	d;

	digit = 1;
	d = va_arg(ap, int);
	digit = ft_putnbr_fd(d, 1, digit);
	argv++;
	return (digit);
}

static int	ft_putnbr_fd(int num, int fd, int digit)
{
	long long	devisor;
	long long	abs_num;

	devisor = 1;
	abs_num = (long long)num;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd((abs_num / devisor) + '0', fd);
		abs_num %= devisor;
		devisor /= 10;
	}
	return (digit);
}
