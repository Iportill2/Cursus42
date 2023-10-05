/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:00 by iportill          #+#    #+#             */
/*   Updated: 2023/07/18 12:30:16 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_pec(t_game *game)
{
	if (game->p != 1)
		ft_error(game, "Diferent than one P", 3);
	if (game->e != 1)
		ft_error(game, "Diferent than one E", 3);
	if (game->c == 0)
		ft_error(game, "The map dont have coleccionables", 3);
}

void	check_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	i = i - 4;
	if (name[i] == '.' && name[i + 1] == 'b' && name[i + 2] == 'e'
		&& name[i + 3] == 'r')
	{
		return ;
	}
	else
	{
		write(1, "Error\nExtension del archivo no valido\n", 38);
		exit(1);
	}
}

void	check_map(t_game *game)
{
	int	i;
	int	u;

	i = 0;
	while (game->map[i])
	{
		u = 0;
		while (game->map[i][u])
		{
			if (game->map[i][u] == 'C')
				game->c++;
			else if (game->map[i][u] == 'P')
			{
				game->p++;
				game_x_to_i(game, i, u);
			}
			else if (game->map[i][u] == 'E')
				game->e++;
			else if (game->map[i][u] != '0' && game->map[i][u] != '1')
				ft_error(game, "Elemento DESCONOCIDO en el mapa", 3);
			u++;
		}
		i++;
	}
}

void	game_x_to_i(t_game *game, int i, int u)
{
	game->x = i;
	game->y = u;
}
