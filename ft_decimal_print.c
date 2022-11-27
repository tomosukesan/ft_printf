/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/27 10:18:06 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_uinbr_fd(unsigned int n, int fd, int digit);

int	ft_decimal_print(const char **argv, va_list ap, t_flags flag)
{
	unsigned int	num;
	int				digit;
	int				result;
	char			c;

	num = va_arg(ap, unsigned int);
	digit = ft_cal_digit(num);
	result = 0;
	c = ' ';
	if (digit >= flag.width)
	{
		result = digit;
		ft_put_uinbr_fd(num, 1, digit);
	}
	else if (digit < flag.width)
	{
		result = flag.width;
		flag.width -= digit;
		if (flag.minus)
		{
			ft_put_uinbr_fd(num, 1, digit);
			while (flag.width--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			if (flag.zero)
				c = '0';
			while (flag.width--)
				ft_putchar_fd(c, 1);
			ft_put_uinbr_fd(num, 1, digit);
		}
	}
	argv++;
	return (result);
}

static int	ft_put_uinbr_fd(unsigned int n, int fd, int digit)
{
	long long	devisor;
	long long	tmp;

	devisor = 1;
	tmp = (long long)n;
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
