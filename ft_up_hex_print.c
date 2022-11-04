/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_hex_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:27:37 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/04 19:47:26 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_up_hex_print(const char **argv, va_list ap)
{
	size_t	x;
	int		digit;

	digit = 1;
	x = va_arg(ap, size_t);
	digit = ft_hex_print(x, UPPERCASE_HEX, digit);
	argv++;
	return (digit);
}
