/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:03:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/22 14:51:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_check_minus_zero(const char **argv, t_flags *flag)
{
	if (**argv == '-')
	{
		flag->minus = TRUE;
		(*argv)++;
	}
	else if (**argv == '0')
	{
		flag->zero = TRUE;
		(*argv)++;
	}
	if (flag->minus && flag->zero)
		flag->zero = FALSE;
}

void	ft_check_space_plus(const char **argv, t_flags *flag)
{
	if (**argv == ' ')
		flag->space = TRUE;
	else if (**argv == '+')
		flag->plus = TRUE;
	(*argv)++;
	if (flag->space && flag->plus)
		flag->space = FALSE;
}

void	ft_check_sharp(const char **argv, t_flags *flag)
{
	if (**argv == '#')
		flag->sharp = TRUE;
	(*argv)++;
	while (**argv == '#')
		(*argv)++;
}

int	ft_cal_width(const char **argv)
{
	long	result;

	result = 0;
	while ('0' <= **argv && **argv <= '9')
	{
		result = result * 10 + (**argv - '0');
		if (result >= INT_MAX)
			return (-1);
		(*argv)++;
	}
	return ((int)result);
}

int	ft_cal_precision(const char **argv, t_flags *flag)
{
	int	result;

	flag->dot = TRUE;
	(*argv)++;
	result = 0;
	while ('0' <= **argv && **argv <= '9')
	{
		if (result >= (INT_MAX - (**argv - '0')) / 10)
			return (-1);
		result = result * 10 + (**argv - '0');
		(*argv)++;
	}
	return (result);
}
