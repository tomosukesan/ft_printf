/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:39 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/06 22:38:10 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_print(unsigned int num, char *rule)
{
	if (num < 16)
	{
		ft_putchar_fd(rule[num % 16], 1);
		return ;
	}
	ft_hex_print(num / 16, rule);
	ft_putchar_fd(rule[num % 16], 1);
}
