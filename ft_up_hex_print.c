/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_hex_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:27:37 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/26 14:46:22 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_up_hex_print(const char **argv, va_list ap)
{
	unsigned int	x;
	int				digit;

	digit = 0;
	x = va_arg(ap, unsigned int);
	digit = ft_hex_print(x, UPPERCASE_HEX, digit);
	argv++;
	return (digit);
}
