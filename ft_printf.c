/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/03 20:39:58 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *argv, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, argv);
	while (*argv != '\0')
	{
		if (*argv == '%')
		{
			if (*(++argv) == 'c')
				result += ft_chr_print(&argv, ap);
			else if (*argv == 's')
				result += ft_str_print(&argv, ap);
			else if (*argv == 'p')
			{
				//c = va_arg(ap, int);
				//ft_putchar_fd(c, 1);
			}
			else if (*argv == 'd' || *argv == 'i')
				result += ft_nbr_print(&argv, ap);
			else if (*argv == 'u')
				result += ft_decimal_print(&argv, ap);
			else if (*argv == 'x')
				result += ft_low_hex_print(&argv, ap);
			else if (*argv == 'X')
				result += ft_up_hex_print(&argv, ap);
			else if (*argv == '%')
				write(1, argv, 1);
			argv++;
		}
		else
		{
			write(1, argv, 1);
			argv++;
			result++;
		}
	}
	va_end(ap);
	return (result);
}
