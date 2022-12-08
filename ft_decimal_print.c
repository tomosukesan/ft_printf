/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:02:21 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_put_uinbr_fd(unsigned int n, int fd, int digit);

int	ft_decimal_print(const char **argv, va_list ap, t_flags flag)
{
	unsigned int	num;
	int				digit;
	int				result;

	num = va_arg(ap, unsigned int);
	digit = ft_cal_abs_digit(num);
	result = flag.width;
	if (flag.precision > digit)
	{
		flag.zero = TRUE;
		if (flag.precision > flag.width)
			result = flag.precision;
	}
	if (digit >= result)
	{
		result = digit;
		ft_put_uinbr_fd(num, 1, digit);
	}
	else if (digit < result)
		ft_decimal_flags(num, digit, flag, result);
	argv++;
	return (result);
}

void	ft_put_uinbr_fd(unsigned int n, int fd, int digit)
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
}
