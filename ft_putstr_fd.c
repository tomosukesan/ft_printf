/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:47:48 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/02 11:16:38 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == NULL)
		return ;
	s_len = ft_strlen(s);
	if (s_len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		write(fd, &s[INT_MAX], s_len - INT_MAX);
	}
	else
		write(fd, s, s_len);
}
