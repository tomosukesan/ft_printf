/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/26 19:13:22 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_print(const char **argv, va_list ap, t_flags flag)
{
	char	*s;
	int		s_len;
	int		result;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	s_len = ft_strlen(s);
	result = 0;
	if (s_len > flag.width)
	{
		result = s_len;
		ft_putstr_fd(s, 1);
	}
	else if (s_len < flag.width)
	{
		result = flag.width;
		flag.width -= s_len;
		if (flag.minus == TRUE)
		{
			ft_putstr_fd(s, 1);
			while (flag.width--)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flag.width--)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(s, 1);
		}
	}
	argv++;
	return (result);
}
