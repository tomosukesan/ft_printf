/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:10:44 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:32:26 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_printf_bonus(const char **argv, t_flags *flag)
{
	if (**argv == '-' || **argv == '0')
		ft_check_minus_zero(argv, flag);
	if (**argv == ' ' || **argv == '+')
	{
		ft_check_space_plus(argv, flag);
		ft_check_minus_zero(argv, flag);
	}
	else if (**argv == '#')
		ft_check_sharp(argv, flag);
	if ('0' <= **argv && **argv <= '9')
		flag->width = ft_cal_width(argv);
	if (flag->width == -1)
		return ;	// ここのエラー処理は必要？
	if (**argv == '.')
		ft_check_dot_precision(argv, flag);
}
