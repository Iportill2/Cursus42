/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:14 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 13:01:18 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_equal(t_game *game, int x, int y, char letter)
{
	if (game->map[x][y] == letter)
		return (1);
	return (0);
}

void	ft_write_moves(t_game *game)
{
	char	*nbr;

	nbr = ft_itoa(game->movements++);
	ft_putendl_fd(nbr, 1);
	ft_put_img(game, 0, 0, game->imgwall);
	ft_put_img(game, 50, 50, game->imgwall);
	mlx_string_put(game->mlx, game->window, 32, 32, ORANGE, nbr);
	mlx_string_put(game->mlx, game->window, 50, 32, ORANGE, "MOVES");
	free(nbr);
}

void	ft_walk(t_game *game, int x, int y)
{
	ft_write_moves(game);
	ft_put_img(game, game->p_x, game->p_y, game->imgfloor);
	if (game->c == 0 && ft_equal(game, game->p_x, game->p_y, 'X'))
		ft_put_img(game, game->p_x, game->p_y, game->imgdemon2);
	if (game->c == 0)
		ft_put_img(game, x, y, game->imgplayer3);
	else if ((x + y) % 2 == 0)
		ft_put_img(game, x, y, game->imgplayer1);
	else
		ft_put_img(game, x, y, game->imgplayer2);
	if (game->e_x == game->p_x && game->e_y == game->p_y)
		ft_put_img(game, game->e_x, game->e_y, game->imgexit1);
}

void	ft_chage_player(t_game *game, int x, int y)
{
	game->p_x = x;
	game->p_y = y;
	if (game->c == 0 && game->p_x == game->e_x && game->p_y == game->e_y)
		ft_error(game, "You Win", 0);
}

void	ft_move(t_game *game, int x, int y)
{
	x += game->p_x;
	y += game->p_y;
	if (ft_equal(game, x, y, '1'))
		return ;
	else if (ft_equal(game, x, y, '0'))
		ft_walk(game, x, y);
	else if (ft_equal(game, x, y, 'C'))
	{
		ft_put_img(game, x, y, game->imgfloor);
		ft_walk(game, x, y);
		game->c--;
		game->map[x][y] = '0';
		if (game->c == 0)
		{
			ft_put_img(game, x, y, game->imgfloor);
			ft_put_img(game, x, y, game->imgplayer3);
			ft_put_img(game, game->e_x, game->e_y, game->imgexit2);
		}
	}
	else if (ft_equal(game, x, y, 'X') && game->c == 0)
		ft_walk(game, x, y);
	else if (ft_equal(game, x, y, 'X'))
		ft_error(game, "You have die", 0);
	ft_chage_player(game, x, y);
}
