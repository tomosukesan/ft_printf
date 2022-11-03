/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_hex_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:40:45 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 19:58:57 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_low_hex_print(const char **argv, va_list ap)
{
	unsigned int	x;
	unsigned int	digit;

	digit = 1;
	// 配列マクロをヘッダーで宣言して〜〜。
	x = va_arg(ap, unsigned int);
	digit = ft_convert_hex(x);
	// 機能　：送った正の10進数を16進数に変換
	// 戻り値：16進数の数値
	return (digit);
}
