/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:29:34 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	judge_detail(const char **argv, va_list ap);
static void	*ft_memset(void *buf, int ch, size_t n);
static int	judge_format(const char **argv, va_list ap, t_flags flag);

int	ft_printf(const char *argv, ...)
{
	va_list	ap;
	int		result;
	int		ret_val;

	result = 0;
	va_start(ap, argv);
	while (*argv != '\0')
	{
		ret_val = 1;
		if (*argv == '%')
		{
			argv++;
			ret_val = judge_detail(&argv, ap);
			if (ret_val < 0)
				return (-1);
			result += ret_val;
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

int	judge_detail(const char **argv, va_list ap)
{
	t_flags	flag;

	ft_memset(&flag, 0, sizeof(t_flags));
	ft_printf_bonus(argv, &flag);
	return (judge_format(argv, ap, flag));
}

void	*ft_memset(void *buf, int ch, size_t n)
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
		result = ft_address_print(argv, ap, flag);
	else if (**argv == 'd' || **argv == 'i')
		result = ft_nbr_print(argv, ap, flag);
	else if (**argv == 'u')
		result = ft_decimal_print(argv, ap, flag);
	else if (**argv == 'x')
		result = ft_handle_hex(argv, ap, LOWERCASE_HEX, flag);
	else if (**argv == 'X')
		result = ft_handle_hex(argv, ap, UPPERCASE_HEX, flag);
	else if (**argv == '%')
		result = ft_putchar_fd('%', 1);
	return (result);
}
