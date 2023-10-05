/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:32:03 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:04:55 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	point;

	if (!s || (!s && !f))
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	output = ft_strdup(s);
	if (!output)
		return (0);
	point = 0;
	while (output[point])
	{
		output[point] = (*f)(point, output[point]);
		point++;
	}
	return (output);
}
