/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:31:18 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:04:39 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	point;

	output = (char *)malloc(\
			(ft_strlen(s1) + ft_strlen(s2) + 1) \
			* sizeof(char));
	if (!output)
		return (NULL);
	point = 0;
	while (*s1)
		output[point++] = *s1++;
	while (*s2)
		output[point++] = *s2++;
	output[point] = '\0';
	return (output);
}
