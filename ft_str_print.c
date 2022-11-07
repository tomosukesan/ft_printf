/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/07 14:40:14 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_str_print(const char **argv, va_list ap)
{
	char	*s;
	int		result;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (-1);
	result = ft_putstr_fd(s, 1);
	argv++;
	return (result);
}
