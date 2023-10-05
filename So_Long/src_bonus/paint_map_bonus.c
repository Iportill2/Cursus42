/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:19 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 16:09:35 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_put_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->window, img, (y * 64), (x * 64));
}

void	ft_put_image(t_game *game, int x, int y)
{
	ft_put_img(game, x, y, game->imgfloor);
	if (ft_equal(game, x, y, '1'))
		ft_put_img(game, x, y, game->imgwall);
	else if (ft_equal(game, x, y, '0'))
		ft_put_img(game, x, y, game->imgfloor);
	else if (ft_equal(game, x, y, 'E'))
		ft_put_img(game, x, y, game->imgexit1);
	else if (ft_equal(game, x, y, 'C'))
		ft_put_img(game, x, y, game->imgcollects);
	else if (ft_equal(game, x, y, 'P'))
	{
		if ((x + y) % 2 == 0)
			ft_put_img(game, x, y, game->imgplayer1);
		else
			ft_put_img(game, x, y, game->imgplayer2);
	}
	else if (ft_equal(game, x, y, 'X'))
		ft_put_img(game, x, y, game->imgdemon1);
	ft_put_img(game, 0, 0, game->imgwall);
}

void	ft_paint_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			ft_put_image(game, x, y);
			y++;
		}
		x++;
	}
	game->map[game->p_x][game->p_y] = '0';
	game->map[game->e_x][game->e_y] = '0';
}
