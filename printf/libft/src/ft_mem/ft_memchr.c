/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:07:51 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:03:48 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	charac;
	size_t			count;

	src = (unsigned char *)s;
	charac = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (src[count] == charac)
			return ((void *)&src[count]);
		count++;
	}
	return (NULL);
}
