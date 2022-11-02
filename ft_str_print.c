/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:41 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 15:07:53 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_str_print(const char **argv, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, 1);
	argv++;
	return ((int)ft_strlen(s));
}
