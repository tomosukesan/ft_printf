/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:40:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/24 19:53:10 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
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
int		ft_chr_print(const char **argv, va_list ap, t_flags flag);
int		ft_putchar_fd(char c, int fd);
int		ft_str_print(const char **argv, va_list ap, t_flags flag);
int		ft_putstr_fd(char *s, int fd);
int		ft_nbr_print(const char **argv, va_list ap, t_flags flag);
int		ft_putnbr_fd(int n, int fd, int digit);
int		ft_decimal_print(const char **argv, va_list ap, t_flags flag);
int		ft_handle_hex(const char **argv, va_list ap, char *rule, t_flags flag);
int		ft_hex_print(unsigned int num, char *rule, int digit);
int		ft_address_print(const char **argv, va_list ap, t_flags flag);
int		ft_strlen(const char *str);
int		ft_cal_width(const char **argv);
int		ft_cal_digit(long long num);
int		ft_cal_hex_digit(unsigned long num, int digit);
void	ft_check_minus_zero(const char **argv, t_flags *flag);
void	ft_check_space_plus(const char **argv, t_flags *flag);
void	ft_check_sharp(const char **argv, t_flags *flag);

#endif