/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:35 by iportill          #+#    #+#             */
/*   Updated: 2023/07/21 12:18:33 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_star_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (int)game->column * 64,
			(int)game->line * 64, "So Long !");
	ft_get_xpm(game);
	ft_paint_map(game);
	ft_hook(game);
	mlx_loop(game->mlx);
}
