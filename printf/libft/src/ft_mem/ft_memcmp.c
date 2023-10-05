/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:15:15 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:03:52 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if (((const unsigned char *)s1)[count] != \
		((const unsigned char *)s2)[count])
			return (((const unsigned char *)s1)[count] \
			- ((const unsigned char *)s2)[count]);
		count++;
	}
	return (0);
}
