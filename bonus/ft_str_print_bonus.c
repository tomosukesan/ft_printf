/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/25 22:52:50 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_str_adapt_width(char *s, int s_len, t_flags flag);

int	ft_str_print_bonus(va_list ap, t_flags flag)
{
	char	*s;
	int		s_len;
	int		result;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	s_len = ft_strlen_bonus(s);
	if (flag.dot && (flag.width == 0 && flag.precision == 0))
		return (0);
	if (flag.dot && s_len > flag.precision)
		s_len = flag.precision;
	if (s_len >= flag.width)
	{
		result = s_len;
		write(1, s, s_len);
	}
	else
		result = ft_str_adapt_width(s, s_len, flag);
	return (result);
}

static int	ft_str_adapt_width(char *s, int s_len, t_flags flag)
{
	int	ret_val;

	ret_val = flag.width;
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
	return (ret_val);
}
