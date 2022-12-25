/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/25 17:50:05 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_plusnbr_fd(unsigned int n);

int	ft_decimal_print(va_list ap)
{
	unsigned int	u;
	int				digit;

	u = va_arg(ap, unsigned int);
	digit = ft_put_plusnbr_fd(u);
	return (digit);
}

static int	ft_put_plusnbr_fd(unsigned int num)
{
	int			digit;
	long long	devisor;
	long long	ll_num;

	digit = 1;
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
		ft_putchar_fd((ll_num / devisor) + '0', 1);
		ll_num %= devisor;
		devisor /= 10;
	}
	return (digit);
}
