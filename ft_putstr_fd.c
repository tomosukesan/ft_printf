/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:47:48 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 17:11:29 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == NULL)
		return (0);
	s_len = ft_strlen(s);
	if (s_len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		write(fd, &s[INT_MAX], s_len - INT_MAX);
	}
	else
		write(fd, s, s_len);
	return ((int)s_len);
}
