/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishable_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:51 by iportill          #+#    #+#             */
/*   Updated: 2023/07/21 16:40:45 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_finishable_map(t_game *game, int x, int y)
{
	if ((game->map_copy[x][y] == 'C' || game->map_copy[x][y] == 'E')
		&& game->map_copy[x][y])
		game->count++;
	if (game->map_copy[x][y] != '1' && game->map_copy[x][y] != 'X'
		&& game->map_copy[x][y])
	{
		game->map_copy[x][y] = '1';
		ft_finishable_map(game, x + 1, y);
		ft_finishable_map(game, x - 1, y);
		ft_finishable_map(game, x, y + 1);
		ft_finishable_map(game, x, y - 1);
	}
}

void	game_xto_px_game_yto_yx(t_game *game)
{
	game->x = game->p_x;
	game->y = game->p_y;
	ft_finishable_map(game, game->x, game->y);
	if (game->count != game->c + 1)
		ft_error(game, "The map isnt finishable", 3);
}

void	repair_buffer3(int fd, char *buffer)
{
	free(buffer);
	close(fd);
	write(1, "Error\nThe map itsn rectangular\n", 31);
	exit(1);
}
