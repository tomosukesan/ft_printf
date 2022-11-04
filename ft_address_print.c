/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:53:52 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/04 19:49:42 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_address_print(const char **argv, va_list ap)
{
	unsigned long long	p;
	int					digit;

	//digit = 0;
	p = va_arg(ap, unsigned long long);
	digit = ft_putstr_fd("0x", 1);
	digit += ft_hex_print(p, LOWERCASE_HEX, digit);
	//digit = ft_hex_print(p, LOWERCASE_HEX, digit);
	argv++;
	return (digit);
}
