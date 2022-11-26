/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:03:38 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/26 18:52:16 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_minus_zero(const char **argv, t_flags *flag)
{
	if (**argv == '-')
		flag->minus = TRUE;
	else if (**argv == '0')
		flag->zero = TRUE;
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
