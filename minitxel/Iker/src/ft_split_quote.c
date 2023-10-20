/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:02:59 by manue             #+#    #+#             */
/*   Updated: 2023/10/17 17:18:21 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	*g_data;

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
	if (s[i] == '"' || s[i] == '\'')
	{
		len++;
		i++;
		while (s[i] != '"' && s[i] != '\'')
		{
			len++;
			i++;
		}
		len++;
	}
	else
	{
		while (s[i] != c && s[i] != '"' && s[i] != '\'' && s[i] != '\0')
		{
			len++;
			i++;
		}
	}
	i = 0;
	str = (char *) malloc (sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (s[start] == '"' || s[start] == '\'')
	{	
		str[i++] = s[start++];
		while (s[start] != '"' && s[start] != '\'')
			str[i++] = s[start++];
		str[i++] = s[start++];
	}
	else
	{
		while (s[start] != c && s[start] != '\0')
			str[i++] = s[start++];
	}
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
		if (s[i] == '"' || s[i] == '\'')
		{
			i++;
			while (s[i] != '"' && s[i] != '\'')
				i++;
			i++;
		}
		if (s[i] == c)
			ok = 1;
		i++;
	}
	return (snbr);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**array = NULL;
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
	array[j] = NULL;
	return (array);
}