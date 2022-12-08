/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:57:01 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:45:33 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_address_blank_handle(t_flags flag, uintptr_t	p, int digit)
{
	if (flag.minus)
	{
		ft_putstr_fd("0x", 1);
		ft_put_address(p, LOWERCASE_HEX, digit);
		while (flag.width--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flag.width--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_put_address(p, LOWERCASE_HEX, digit);
	}
}
