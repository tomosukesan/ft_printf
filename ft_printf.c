/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/25 18:58:00 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	judge_format(const char **argv, va_list ap);

int	ft_printf(const char *argv, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, argv);
	while (*argv != '\0')
	{
		if (*argv == '%')
			result += judge_format(&argv, ap);
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

static int	judge_format(const char **argv, va_list ap)
{
	int	result;

	result = 0;
	(*argv)++;
	if (**argv == 'c')
		result = ft_chr_print(argv, ap);
	else if (**argv == 's')
		result = ft_str_print(argv, ap);
	else if (**argv == 'p')
		result = ft_address_print(argv, ap);
	else if (**argv == 'd' || **argv == 'i')
		result = ft_nbr_print(argv, ap);
	else if (**argv == 'u')
		result = ft_decimal_print(argv, ap);
	else if (**argv == 'x')
		result = ft_low_hex_print(argv, ap);
	else if (**argv == 'X')
		result = ft_up_hex_print(argv, ap);
	else if (**argv == '%')
		result = ft_putchar_fd('%', 1);
	(*argv)++;
	return (result);
}
