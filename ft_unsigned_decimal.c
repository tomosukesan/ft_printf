/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 17:21:24 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_put_plusnbr_fd(unsigned int n, int fd, int digit);

int	ft_unsigned_decimal(const char **argv, va_list ap)
{
	int				digit;
	unsigned int	u;

	digit = 1;
	u = va_arg(ap, int);
	digit = ft_put_plusnbr_fd(u, 1, digit);
	argv++;
	return (digit);
}

static int	ft_put_plusnbr_fd(unsigned int n, int fd, int digit)
{
	long long	devisor;
	long long	tmp;

	devisor = 1;
	tmp = (long long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp *= -1;
		digit++;
	}
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
	return (digit);
}
