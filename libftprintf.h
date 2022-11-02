/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:40:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 17:05:28 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *argv, ...);
int		ft_chr_print(const char **argv, va_list ap);
int		ft_str_print(const char **argv, va_list ap);
int		ft_putstr_fd(char *s, int fd);
int		ft_nbr_print(const char **argv, va_list ap);
int		ft_putnbr_fd(int n, int fd, int digit);
int		ft_unsigned_decimal(const char **argv, va_list ap);

#endif