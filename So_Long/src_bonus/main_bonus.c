/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:35:51 by iportill          #+#    #+#             */
/*   Updated: 2023/07/17 16:09:19 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		check_name(argv[1]);
		ft_init_game(&game);
		ft_create_maps(argv[1], &game);
		game.line = count_lines(&game);
		game.column = count_columns(&game);
		define_px_py_position(game.map, &game);
		define_ex_ey_position(game.map, &game);
		check_map(&game);
		check_pec(&game);
		ft_check_wall(&game);
		game_xto_px_game_yto_yx(&game);
		ft_star_game(&game);
	}
	return (0);
}
