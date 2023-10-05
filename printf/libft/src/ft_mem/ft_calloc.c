/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:26:38 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:03:44 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	size_t	x;

	x = count * size;
	if (count != 0 && x / count != size)
		return (NULL);
	c = (void *)malloc(count * size);
	if (c)
		ft_memset(c, 0, count * size);
	return (c);
}
