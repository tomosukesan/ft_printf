/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 17:12:58 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
