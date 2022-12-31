/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 21:47:43 by ttachi           ###   ########.fr       */
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
	int		digit;
	long	devisor;
	long	l_num;

	digit = 1;
	devisor = 1;
	l_num = (long)num;
	while (num >= 10)
	{
		devisor *= 10;
		num /= 10;
		digit++;
	}
	while (devisor)
	{
		ft_putchar_fd((l_num / devisor) + '0', 1);
		l_num %= devisor;
		devisor /= 10;
	}
	return (digit);
}
