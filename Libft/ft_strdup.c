/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:27:33 by iportill          #+#    #+#             */
/*   Updated: 2022/12/12 15:17:12 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*output;

	len = ft_strlen(s1);
	output = (char *)malloc((len + 1) * sizeof(*output));
	if (output)
		ft_memcpy(output, s1, len + 1);
	return (output);
}
