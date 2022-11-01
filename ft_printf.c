/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:27 by ttachi            #+#    #+#             */
/*   Updated: 2022/10/31 18:02:24 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
//#include "libftprintf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


int	ft_printf(const char *arg, ...)
{
	char	*tmp;
	int		write_count;

	tmp = (char *)arg;
	write_count = 0;
	while (*tmp != '\0')
	{
		write(1, tmp++, 1);
		write_count++;
	}
	return (write_count);
}

int	main(void)
{
	ft_printf("Hello World.");
	return (0);
}
