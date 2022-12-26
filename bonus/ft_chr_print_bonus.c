/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:38:40 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/25 22:47:40 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_chr_print_bonus(va_list ap, t_flags flag)
{
	char	c;
	int		result;

	c = va_arg(ap, int);
	if (flag.width <= 1)
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	result = flag.width;
	if (flag.minus)
	{
		ft_putchar_fd(c, 1);
		while (--flag.width > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--flag.width > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	return (result);
}
