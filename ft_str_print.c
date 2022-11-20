/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/20 14:01:22 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_str_print(const char **argv, va_list ap)
{
	char	*s;
	int		result;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
	}
	result = ft_putstr_fd(s, 1);
	argv++;
	return (result);
}
