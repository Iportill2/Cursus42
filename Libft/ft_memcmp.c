/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:15:15 by iportill          #+#    #+#             */
/*   Updated: 2022/12/12 15:14:01 by iportill         ###   ########.fr       */
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
