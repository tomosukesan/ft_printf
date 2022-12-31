/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/31 21:52:32 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_strlen_bonus(const char *str);
static int	ft_process_other(char *s, int s_len, t_flags flag);
static void	ft_str_adapt_width(char *s, int s_len, t_flags flag);

int	ft_str_print_bonus(va_list ap, t_flags flag)
{
	char	*s;
	int		s_len;
	int		result;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	s_len = ft_strlen_bonus(s);
	if (s_len < 0)
		return (-1);
	if (flag.dot && (flag.width == 0 && flag.precision == 0))
		return (0);
	if (flag.width > flag.precision && flag.width > s_len)
	{
		result = flag.width;
		if (flag.dot && flag.precision < s_len)
			ft_str_adapt_width(s, flag.precision, flag);
		else
			ft_str_adapt_width(s, s_len, flag);
	}
	else
		result = ft_process_other(s, s_len, flag);
	return (result);
}

static int	ft_process_other(char *s, int s_len, t_flags flag)
{
	int	result;

	if ((flag.precision > flag.width && flag.precision > s_len) || !flag.dot)
	{
		result = s_len;
		write(1, s, s_len);
	}
	else
	{
		ft_str_adapt_width(s, flag.precision, flag);
		if (flag.width >= flag.precision)
			result = flag.width;
		else
			result = flag.precision;
	}
	return (result);
}

static void	ft_str_adapt_width(char *s, int s_len, t_flags flag)
{
	flag.width -= s_len;
	if (flag.minus)
	{
		write(1, s, s_len);
		while (flag.width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flag.width-- > 0)
			ft_putchar_fd(' ', 1);
		write(1, s, s_len);
	}
}

static int	ft_strlen_bonus(const char *str)
{
	long	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (len > INT_MAX)
		return (-1);
	return ((int)len);
}
