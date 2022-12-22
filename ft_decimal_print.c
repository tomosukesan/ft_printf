/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/22 10:47:42 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_plusnbr_fd(unsigned int n, int fd, int digit);

int	ft_decimal_print(const char **argv, va_list ap)
{
	int				digit;
	unsigned int	u;

	digit = 1;
	u = va_arg(ap, unsigned int);
	digit = ft_put_plusnbr_fd(u, 1, digit);
	argv++;
	return (digit);
}

static int	ft_put_plusnbr_fd(unsigned int num, int fd, int digit)
{
	long long	devisor;
	long long	ll_num;

	devisor = 1;
	ll_num = (long long)num;
	while (num >= 10)
	{
		devisor *= 10;
		num /= 10;
		digit++;
	}
	while (devisor)
	{
		ft_putchar_fd((ll_num / devisor) + '0', fd);
		ll_num %= devisor;
		devisor /= 10;
	}
	return (digit);
}
