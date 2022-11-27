/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:03:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/27 13:48:18 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (**argv == '-' || **argv == '0')
		(*argv)++;
}

void	ft_check_space_plus(const char **argv, t_flags *flag)
{
	if (**argv == ' ')
		flag->space = TRUE;
	else if (**argv == '+')
		flag->plus = TRUE;
	(*argv)++;
	while (**argv == ' ' || **argv == '+')
		(*argv)++;
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
	int	result;

	while ('0' <= **argv && **argv <= '9')
	{
		if (result >= (INT_MAX - (**argv - '0')) / 10)
			return (-1);
		result = result * 10 + (**argv - '0');
		(*argv)++;
	}
	return (result);
}
