/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:39 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/04 19:43:51 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hex_print(unsigned long long num, char *rule, int digit)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return (digit);
	}
	digit = ft_hex_print(num / 16, rule, digit) + 1;
	ft_putchar_fd(rule[num % 16], 1);
	return (digit);
}
