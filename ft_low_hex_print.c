/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_hex_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/24 17:04:01 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_low_hex_print(const char **argv, va_list ap)
{
	unsigned int	x;
	int				digit;

	digit = 0;
	x = va_arg(ap, unsigned int);
	digit = ft_hex_print(x, LOWERCASE_HEX, digit);
	argv++;
	return (digit);
}
