/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:38:40 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/24 14:55:24 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_chr_print(const char **argv, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	argv++;
	return (1);
}
