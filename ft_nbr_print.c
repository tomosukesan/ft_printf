/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/27 10:04:10 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adapt_flags_with_minus(int num, int digit, t_flags flag);
static void	adapt_flags(int num, int digit, t_flags flag);

int	ft_nbr_print(const char **argv, va_list ap, t_flags flag)
{
	int		num;
	int		digit;
	int		result;

	num = va_arg(ap, int);
	digit = ft_cal_digit(num);
	result = 0;
	if (digit >= flag.width)
	{
		result = digit;
		ft_putnbr_fd(num, 1, digit);
	}
	else if (digit < flag.width)
	{
		result = flag.width;
		flag.width -= digit;
		if (flag.minus)
			adapt_flags_with_minus(num, digit, flag);
		else
			adapt_flags(num, digit, flag);
	}
	argv++;
	return (result);
}

static void	adapt_flags_with_minus(int num, int digit, t_flags flag)
{
	if (flag.space)
	{
		ft_putchar_fd(' ', 1);
		flag.width--;
	}
	else if (flag.plus)
	{
		ft_putchar_fd('+', 1);
		flag.width--;
	}
	ft_putnbr_fd(num, 1, digit);
	while (flag.width--)
		ft_putchar_fd(' ', 1);
}

static void	adapt_flags(int num, int digit, t_flags flag)
{
	char	c;

	c = ' ';
	if (flag.space)
	{
		ft_putchar_fd(' ', 1);
		flag.width--;
	}
	else if (flag.plus)
	{
		ft_putchar_fd('+', 1);
		flag.width--;
	}
	if (flag.zero)
		c = '0';
	while (flag.width--)
		ft_putchar_fd(c, 1);
	ft_putnbr_fd(num, 1, digit);
}
