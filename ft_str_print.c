/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:17:02 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_str_print(const char **argv, va_list ap, t_flags flag)
{
	char	*s;
	int		s_len;
	int		result;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_putstr_fd("(null)", 1));
	s_len = ft_strlen(s);
	if (flag.dot && (flag.width == 0 && flag.precision == 0))
		return (0);
	if (flag.dot && s_len > flag.precision)
		s_len = flag.precision;
	result = 0;
	if (s_len >= flag.width)
	{
		result = s_len;
		write(1, s, s_len);
	}
	else if (s_len < flag.width)
		result = ft_str_write_in_width(s, s_len, flag);
	argv++;
	return (result);
}
