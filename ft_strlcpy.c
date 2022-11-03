/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:33:28 by ttachi            #+#    #+#             */
/*   Updated: 2022/11/03 19:33:53 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t				count;
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;

	count = 0;
	uc_dest = (unsigned char *)dest;
	uc_src = (const unsigned char *)src;
	if (destsize == 0)
		return (ft_strlen(src));
	while (count < destsize - 1)
	{
		uc_dest[count] = uc_src[count];
		if (uc_src[count] == '\0')
			return (ft_strlen(src));
		count++;
	}
	uc_dest[count] = '\0';
	return (ft_strlen(src));
}