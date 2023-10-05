/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:09 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 16:08:56 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_destroy(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
}

int	close_window(t_game *game)
{
	ft_error(game, "You close the window", 0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == Q || keycode == ESC)
		ft_error(game, "You close the window", 0);
	else if (keycode == W)
		ft_move(game, -1, 0);
	else if (keycode == D)
		ft_move(game, 0, 1);
	else if (keycode == A)
		ft_move(game, 0, -1);
	else if (keycode == S)
		ft_move(game, 1, 0);
	return (0);
}

void	ft_hook(t_game *game)
{
	mlx_hook(game->window, 17, 1, close_window, game);
	mlx_hook(game->window, 2, 1, key_press, game);
}
