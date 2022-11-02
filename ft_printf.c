/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 15:09:37 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *argv, ...)
{
	va_list ap;
	int		result;
	int d;

	result = 0;
	va_start(ap, argv);
	while (*argv != '\0')
	{
		if (*argv == '%')
		{
			// 戻り値はintでargvは参照渡しでいこう。putnbrとかとの兼ね合いを考慮してね
			if (*(++argv) == 'c')
				result += ft_chr_print(&argv, ap);
			else if (*argv == 's')
				result += ft_str_print(&argv, ap);
			else if (*argv == 'p')
			{
				//c = va_arg(ap, int);
				//ft_putchar_fd(c, 1);
			}
			else if (*argv == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr_fd(d, 1);
			}
			else if (*argv == '%')
				write(1, argv, 1);
			argv++;
		}
		else
		{
			write(1, argv, 1);
			argv++;
		}
		result++;
	}
	va_end(ap);
	return (result);
}
