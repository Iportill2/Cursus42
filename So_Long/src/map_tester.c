/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:30 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 15:57:44 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

int	count_columns(t_game *game)
{
	int	lenght;
	int	i;

	lenght = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != lenght)
		{
			ft_error (game, "The map NOT rectangle\n", 3);
		}
		else
		{
			i++;
		}
	}
	return (lenght);
}
