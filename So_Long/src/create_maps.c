/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:47 by iportill          #+#    #+#             */
/*   Updated: 2023/07/21 16:40:32 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_create_maps(char *map_name, t_game *game)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = ft_open_file(map_name);
	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	if (buffer[0] == '\0' )
		repair_buffer1(fd, buffer);
	else if (buffer[0] == '\n')
		repair_buffer3(fd, buffer);
	while (buffer[i])
	{
		if ((buffer[i] == '\n' && buffer[i + 1] == '\n') || (buffer[i] == '\n'
				&& buffer[i + 1] == '\0'))
			repair_buffer2(fd, buffer);
		i++;
	}
	game->map = ft_split(buffer, '\n');
	game->map_copy = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}

void	define_px_py_position(char **array, t_game *game)
{
	int	y;
	int	x;

	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
			}
			y++;
		}
		x++;
	}
	return ;
}

void	define_ex_ey_position(char **array, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'E')
			{
				game->e_x = x;
				game->e_y = y;
			}
			y++;
		}
		x++;
	}
	return ;
}
