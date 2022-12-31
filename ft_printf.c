/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 18:13:27 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	judge_format(const char **argv, va_list ap);

int	ft_printf(const char *argv, ...)
{
	va_list	ap;
	long	result;
	int		ret_val;

	result = 0;
	va_start(ap, argv);
	while (*argv != '\0')
	{
		if (*argv == '%')
		{
			argv++;
			ret_val = judge_format(&argv, ap);
			if (ret_val < 0)
				return (-1);
			result += ret_val;
		}
		else
			result += ft_putchar_fd(*argv, 1);
		if (result > INT_MAX)
			return (-1);
		argv++;
	}
	va_end(ap);
	return ((int)result);
}

static int	judge_format(const char **argv, va_list ap)
{
	int	result;

	result = 0;
	if (**argv == 'c')
		result = ft_chr_print(ap);
	else if (**argv == 's')
		result = ft_str_print(ap);
	else if (**argv == 'p')
		result = ft_address_print(ap);
	else if (**argv == 'd' || **argv == 'i')
		result = ft_nbr_print(ap);
	else if (**argv == 'u')
		result = ft_decimal_print(ap);
	else if (**argv == 'x')
		result = ft_low_hex_print(ap);
	else if (**argv == 'X')
		result = ft_up_hex_print(ap);
	else if (**argv == '%')
		result = ft_putchar_fd('%', 1);
	(*argv)++;
	return (result);
}
