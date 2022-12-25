/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:40:07 by ttachi            #+#    #+#             */
/*   Updated: 2022/12/25 17:30:47 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <inttypes.h>

# define LOWERCASE_HEX "0123456789abcdef"
# define UPPERCASE_HEX "0123456789ABCDEF"

int	ft_printf(const char *argv, ...);
int	ft_chr_print(va_list ap);
int	ft_putchar_fd(char c, int fd);
int	ft_str_print(va_list ap);
int	ft_putstr_fd(char *s, int fd);
int	ft_nbr_print(va_list ap);
int	ft_decimal_print(va_list ap);
int	ft_low_hex_print(va_list ap);
int	ft_up_hex_print(va_list ap);
int	ft_hex_print(unsigned int num, char *rule, int digit);
int	ft_address_print(va_list ap);

#endif