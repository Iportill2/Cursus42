/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:21:05 by iportill          #+#    #+#             */
/*   Updated: 2023/10/18 19:34:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_del(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(array[i++]);
	free(array);
	return (NULL);
}

static char	*ft_subsplit(char const *s, char c, int i)
{
	int		len;
	char	*str;
	int		start;

	start = i;
	len = 1;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	str = (char *) malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (s[start] != c && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static int	ft_strcount(const char *s, char c)
{
	int	i;
	int	snbr;
	int	ok;

	i = 0;
	snbr = 0;
	ok = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && ok == 1)
		{
			snbr++;
			ok = 0;
		}
		if (s[i] == c)
			ok = 1;
		i++;
	}
	return (snbr);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	array = (char **) malloc (sizeof(char *) * ((ft_strcount(s, c)) + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			str = ft_subsplit(s, c, i);
			if (!str)
				return (ft_del(array, j));
			array[j++] = str;
			i = i + ft_strlen(str) - 1;
		}
	}
	array[j] = 0;
	return (array);
}

/*int	main(void)
{
	//char	s[] = "-zapato-gato----julio-agosto-mosto";
	//char	s[] = "Hleo!e";
	char	c;
	char	**res;
	int		i;

	i = 0;
	c = '-';
	//res = (char **) malloc (sizeof(char *) * 100);
	res = ft_split(NULL, c);
	while (res && res[i])
	{
		printf ("%s\n", res[i]);
		i++;
	}
	return (0);
}*/