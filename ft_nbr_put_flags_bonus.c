/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_put_flags_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:49:55 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:40:09 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr_put_flags(t_flags flag, int n, int z_cnt)
{
	if (flag.space && n >= 0)
		ft_putchar_fd(' ', 1);
	else if (flag.plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (n < 0)
		ft_putchar_fd('-', 1);
	if (flag.zero)
		while (z_cnt-- > 0)
			ft_putchar_fd('0', 1);
}

int	ft_adapt_space_plus(t_flags flag, int num, int abs_digit, int minus)
{
	int	result;

	result = 0;
	if (flag.space && num >= 0)
	{
		ft_putchar_fd(' ', 1);
		result++;
	}
	else if (flag.plus && num >= 0)
	{
		ft_putchar_fd('+', 1);
		result++;
	}
	ft_putnbr_fd(num, 1, abs_digit + minus);
	return (result);
}
