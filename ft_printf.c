/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/26 19:26:38 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	judge_detail(const char **argv, va_list ap);
static void	*ft_memset(void *buf, int ch, size_t n);
static int	judge_format(const char **argv, va_list ap, t_flags flag);

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
			argv++;
			result += judge_detail(&argv, ap);		// 失敗の処理を追加
			// result += judge_format(&argv, ap);
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

static int	judge_detail(const char **argv, va_list ap)
{
	t_flags	flag;		//printf("%10c\n", c)

	ft_memset(&flag, 0, 8);
	if (**argv == '-' || **argv == '0')
		ft_check_minus_zero(argv, &flag);
	if ('0' <= **argv && **argv <= '9')
		flag.width = ft_cal_width(argv);
	return (judge_format(argv, ap, flag));
}

static void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			count;
	unsigned char	*uc_buf;

	count = 0;
	uc_buf = (unsigned char *)buf;
	while (count < n)
	{
		uc_buf[count] = (unsigned char)ch;
		count++;
	}
	return ((void *)uc_buf);
}

static int	judge_format(const char **argv, va_list ap, t_flags flag)
{
	int	result;

	result = 0;
	if (**argv == 'c')
		result = ft_chr_print(argv, ap, flag);
	else if (**argv == 's')
		result = ft_str_print(argv, ap, flag);
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
	return (result);
}
