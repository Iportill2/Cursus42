/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:39:15 by iportill          #+#    #+#             */
/*   Updated: 2022/12/12 15:18:15 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			count;
	unsigned int	point;

	count = ft_strlen(src);
	if (!dstsize)
		return (count);
	point = 0;
	while (src[point] && point < dstsize - 1)
	{
		dst[point] = src[point];
		point++;
	}
	dst[point] = '\0';
	return (count);
}

/*int	main(void)
{
	char src[] = "World";
	char dest[] = "He";
	printf("%zu | %s", ft_strlcpy(dest, src, 5), dest);
}*/