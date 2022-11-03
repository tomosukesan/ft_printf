/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:40:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 19:56:29 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

# define LOWERCASE_HEX "123456789abcdef"
# define UPPERCASE_HEX "123456789ABCDEF"

size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *argv, ...);
int		ft_chr_print(const char **argv, va_list ap);
int		ft_str_print(const char **argv, va_list ap);
int		ft_putstr_fd(char *s, int fd);
int		ft_nbr_print(const char **argv, va_list ap);
int		ft_putnbr_fd(int n, int fd, int digit);
int		ft_decimal_print(const char **argv, va_list ap);
int		ft_low_hex_print(const char **argv, va_list ap);

#endif