/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:52:44 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/07 21:40:33 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

void	ft_printf_bonus(const char **argv, t_flags *flag);
void	ft_nbr_flags(t_flags flag, int num, int abs_dig, int width);
void	ft_nbr_put_flags(t_flags flag, int n, int z_cnt);
int		ft_adapt_space_plus(t_flags flag, int num, int abs_digit, int minus);
void	ft_hex_flags(unsigned int x, int width, t_flags flag, char *rule);
int		ft_cal_width(const char **argv);
void	ft_check_minus_zero(const char **argv, t_flags *flag);
void	ft_check_space_plus(const char **argv, t_flags *flag);
void	ft_check_sharp(const char **argv, t_flags *flag);
void	ft_check_dot_precision(const char **argv, t_flags *flag);
void	ft_decimal_flags(unsigned int num, int digit, t_flags flag, int width);
void	ft_address_blank_handle(t_flags flag, uintptr_t	p, int digit);
int		ft_str_write_in_width(char *s, int s_len, t_flags flag);

#endif
