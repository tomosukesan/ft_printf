/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:40:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/04 20:12:23 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

# define LOWERCASE_HEX "0123456789abcdef"
# define UPPERCASE_HEX "0123456789ABCDEF"

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *argv, ...);
int		ft_chr_print(const char **argv, va_list ap);
int		ft_str_print(const char **argv, va_list ap);
int		ft_putstr_fd(char *s, int fd);
int		ft_nbr_print(const char **argv, va_list ap);
int		ft_putnbr_fd(int n, int fd, int digit);
int		ft_decimal_print(const char **argv, va_list ap);
int		ft_low_hex_print(const char **argv, va_list ap);
int		ft_up_hex_print(const char **argv, va_list ap);
int		ft_hex_print(unsigned int num, char *rule, int digit);
int		ft_address_print(const char **argv, va_list ap);
char	*ft_strdup(const char *s1);

#endif