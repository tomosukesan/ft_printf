/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/08 12:07:18 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_print(const char **argv, va_list ap)
{
	int	digit;
	int	d;

	digit = 1;
	d = va_arg(ap, int);
	digit = ft_putnbr_fd(d, 1, digit);
	argv++;
	return (digit);
}
