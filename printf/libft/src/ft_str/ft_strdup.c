/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:27:33 by iportill          #+#    #+#             */
/*   Updated: 2023/03/08 17:04:32 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

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
