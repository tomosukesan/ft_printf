/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:11:22 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 18:05:41 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_fd(int num, int fd)
{
	long	devisor;
	long	abs_num;

	devisor = 1;
	abs_num = (long)num;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		abs_num *= -1;
	}
	while (num <= -10 || num >= 10)
	{
		devisor *= 10;
		num /= 10;
	}
	while (devisor)
	{
		ft_putchar_fd((abs_num / devisor) + '0', fd);
		abs_num %= devisor;
		devisor /= 10;
	}
}
