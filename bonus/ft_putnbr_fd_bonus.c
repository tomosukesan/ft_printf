/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:11:22 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/08 20:45:38 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	devisor;
	long long	tmp;

	devisor = 1;
	tmp = (long long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp *= -1;
	}
	while (n <= -10 || n >= 10)
	{
		devisor *= 10;
		n /= 10;
	}
	while (devisor)
	{
		ft_putchar_fd((tmp / devisor) + '0', fd);
		tmp %= devisor;
		devisor /= 10;
	}
}
