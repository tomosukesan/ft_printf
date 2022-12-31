/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 18:11:05 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_judge_detail(const char **argv, va_list ap);
static void	*ft_memset(void *buf, int ch, size_t n);
static char	*ft_strchr(const char *s, int c);
static int	ft_judge_format(const char **argv, va_list ap, t_flags flag);

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
			ret_val = ft_judge_detail(&argv, ap);
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

static int	ft_judge_detail(const char **argv, va_list ap)
{
	t_flags	flag;

	ft_memset(&flag, 0, sizeof(t_flags));
	while (ft_strchr("-0 +#", **argv))
	{
		if (**argv == '-' || **argv == '0')
			ft_check_minus_zero(argv, &flag);
		if (**argv == '+' || **argv == ' ')
			ft_check_space_plus(argv, &flag);
		else if (**argv == '#')
			ft_check_sharp(argv, &flag);
	}
	if ('0' <= **argv && **argv <= '9')
		flag.width = ft_cal_field_num(argv);
	if (**argv == '.')
	{
		flag.dot = TRUE;
		(*argv)++;
		flag.precision = ft_cal_field_num(argv);
	}
	if (flag.width == -1 || flag.precision == -1)
		return (-1);
	return (ft_judge_format(argv, ap, flag));
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

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

static int	ft_judge_format(const char **argv, va_list ap, t_flags flag)
{
	int	result;

	result = 0;
	if (**argv == 'c')
		result = ft_chr_print_bonus(ap, flag);
	else if (**argv == 's')
		result = ft_str_print_bonus(ap, flag);
	else if (**argv == 'p')
		result = ft_address_print_bonus(ap, flag);
	else if (**argv == 'd' || **argv == 'i')
		result = ft_nbr_print_bonus(ap, flag);
	else if (**argv == 'u')
		result = ft_decimal_print_bonus(ap, flag);
	else if (**argv == 'x')
		result = ft_hex_process(ap, LOWERCASE_HEX, flag);
	else if (**argv == 'X')
		result = ft_hex_process(ap, UPPERCASE_HEX, flag);
	else if (**argv == '%')
		result = ft_putchar_fd('%', 1);
	return (result);
}
