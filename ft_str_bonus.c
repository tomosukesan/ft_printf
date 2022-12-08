/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:14:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:16:26 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_write_in_width(char *s, int s_len, t_flags flag)
{
	int	ret_val;

	ret_val = flag.width;
	flag.width -= s_len;
	if (flag.minus)
	{
		write(1, s, s_len);
		while (flag.width--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flag.width--)
			ft_putchar_fd(' ', 1);
		write(1, s, s_len);
	}
	return (ret_val);
}
