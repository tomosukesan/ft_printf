/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/25 19:17:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(uintptr_t num, char *rule, int digit);

int	ft_address_print(va_list ap)
{
	uintptr_t	p;
	int			digit;

	p = va_arg(ap, uintptr_t);
	ft_putstr_fd("0x", 1);
	digit = ft_put_hex(p, LOWERCASE_HEX, 0);
	return (digit + 2);
}

static int	ft_put_hex(uintptr_t num, char *rule, int digit)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return (++digit);
	}
	digit++;
	digit = ft_put_hex(num / 16, rule, digit);
	ft_putchar_fd(rule[num % 16], 1);
	return (digit);
}
