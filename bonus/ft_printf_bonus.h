/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:52:44 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/28 21:22:12 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <inttypes.h>

# define LOWERCASE_HEX "0123456789abcdef"
# define UPPERCASE_HEX "0123456789ABCDEF"
# define TRUE 1
# define FALSE 0

typedef struct s_flags
{
	char	minus;
	char	zero;
	char	dot;
	int		width;
	int		precision;
	char	sharp;
	char	space;
	char	plus;
}	t_flags;

int		ft_printf(const char *argv, ...);
void	ft_check_minus_zero(const char **argv, t_flags *flag);
void	ft_check_space_plus(const char **argv, t_flags *flag);
void	ft_check_sharp(const char **argv, t_flags *flag);
int		ft_cal_field_num(const char **argv);
int		ft_chr_print_bonus(va_list ap, t_flags flag);
int		ft_str_print_bonus(va_list ap, t_flags flag);
int		ft_address_print_bonus(va_list ap, t_flags flag);
int		ft_nbr_print_bonus(va_list ap, t_flags flag);
void	ft_nbr_flags(t_flags flag, int num, int abs_dig);
int		ft_decimal_print_bonus(va_list ap, t_flags flag);
int		ft_hex_process(va_list ap, char *rule, t_flags flag);
void	ft_hex_print(unsigned int num, char *rule);
int		ft_hex_prefix(unsigned int x, t_flags flag, char *rule);
int		ft_hex_flags(unsigned int x, int width, t_flags flag, char *rule);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_cal_abs_digit(long long num);
int		ft_cal_hex_digit(unsigned long num);

#endif
