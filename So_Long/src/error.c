/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:42 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 14:02:20 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_split(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		free(game->map_copy[x]);
		x++;
	}
	free(game->map);
	free(game->map_copy);
}

void	ft_free(t_game *game)
{
	if (game)
	{
		if (game->map)
			ft_free_split(game);
		if (game->mlx)
			free(game->mlx);
	}
}

void	ft_error(t_game *game, char *text, int error)
{
	if (error)
		ft_putendl_fd("Error", 1);
	if (error != 3)
		ft_destroy(game);
	ft_free(game);
	ft_putendl_fd(text, 1);
	exit(0);
}

void	repair_buffer1(int fd, char *buffer)
{
	free(buffer);
	close(fd);
	write(1, "Error\nThe map its empty\n", 24);
	exit(1);
}

void	repair_buffer2(int fd, char *buffer)
{
	free(buffer);
	close(fd);
	write(1, "Error\nThe map NOT rectangle\n", 28);
	exit(1);
}
