/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:03:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 18:04:41 by ttachi           ###   ########.fr       */
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
	if (**argv == '+')
		flag->plus = TRUE;
	else if (**argv == ' ')
		flag->space = TRUE;
	(*argv)++;
	if (flag->plus && flag->space)
		flag->space = FALSE;
}

void	ft_check_sharp(const char **argv, t_flags *flag)
{
	if (**argv == '#')
		flag->sharp = TRUE * 2;
	(*argv)++;
	while (**argv == '#')
		(*argv)++;
}

int	ft_cal_field_num(const char **argv)
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
