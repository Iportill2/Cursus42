/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:03 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 16:08:53 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_xpm_checker(t_game *game)
{
	if (!game->imgplayer1 || !game->imgplayer2 || !game->imgplayer3
		|| !game->imgwall || !game->imgfloor || !game->imgexit1
		|| !game->imgexit2 || !game->imgcollects || !game->imgdemon1
		|| !game->imgdemon2)
		ft_error(game, "Textures not found", 1);
}

void	ft_get_xpm(t_game *game)
{
	int	x;
	int	y;

	game->imgplayer1 = mlx_xpm_file_to_image(game->mlx, AVATAR1, &(x), &(y));
	game->imgplayer2 = mlx_xpm_file_to_image(game->mlx, AVATAR2, &(x), &(y));
	game->imgplayer3 = mlx_xpm_file_to_image(game->mlx, AVATAR3, &(x), &(y));
	game->imgdemon1 = mlx_xpm_file_to_image(game->mlx, DEMON1, &(x), &(y));
	game->imgdemon2 = mlx_xpm_file_to_image(game->mlx, DEMON2, &(x), &(y));
	game->imgwall = mlx_xpm_file_to_image(game->mlx, WALLS, &(x), &(y));
	game->imgfloor = mlx_xpm_file_to_image(game->mlx, FLOORS, &(x), &(y));
	game->imgexit1 = mlx_xpm_file_to_image(game->mlx, EXIT1, &(x), &(y));
	game->imgexit2 = mlx_xpm_file_to_image(game->mlx, EXIT2, &(x), &(y));
	game->imgcollects = mlx_xpm_file_to_image(game->mlx, COLLECT, &(x), &(y));
	ft_xpm_checker(game);
}
