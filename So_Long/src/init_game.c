/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:24 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 15:57:26 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_game(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->mlx = NULL;
	game->line = 0;
	game->column = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->c = 0;
	game->e = 0;
	game->p = 0;
	game->count = 0;
	game->movements = 0;
}
