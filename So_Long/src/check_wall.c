/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:42 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 16:48:12 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_position(t_game *game, int x, int y)
{
	if (ft_equal(game, x, y, 'P'))
	{
		game->p_x = x;
		game->p_y = y;
	}
	if (ft_equal(game, x, y, 'E'))
	{
		game->e_x = x;
		game->e_y = y;
	}
}

void	ft_check_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->line)
	{
		if (game->map[x][0] != '1' || game->map[x][game->column - 1] != '1')
		{
			ft_error(game, "No walls around the edges COLUMN", 3);
		}
		x++;
	}
	while (y < game->column)
	{
		if (game->map[0][y] != '1' || game->map[game->line - 1][y] != '1')
		{
			ft_error(game, "No walls around the edges LINE", 3);
		}
		y++;
	}
}
