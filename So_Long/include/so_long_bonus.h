/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:33:52 by iportill          #+#    #+#             */
/*   Updated: 2023/07/21 12:28:11 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# define BUFFER_SIZE 9999999
# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35
# define AVATAR1 "textures/avatar1.xpm"
# define AVATAR2 "textures/avatar2.xpm"
# define AVATAR3 "textures/avatar3.xpm"
# define DEMON1 "textures/demon1.xpm"
# define DEMON2 "textures/demon2.xpm"
# define WALLS "textures/wall.xpm"
# define FLOORS "textures/floor.xpm"
# define EXIT1 "textures/exit2.xpm"
# define EXIT2 "textures/exit1.xpm"
# define COLLECT "textures/collect.xpm"
# define KILL 1
# define ORANGE 0xFE6500

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		movements;
	void	*imgplayer1;
	void	*imgplayer2;
	void	*imgplayer3;
	void	*imgdemon1;
	void	*imgdemon2;
	void	*imgwall;
	void	*imgfloor;
	void	*imgexit1;
	void	*imgexit2;
	void	*imgcollects;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		line;
	int		column;
	int		c;
	int		e;
	int		p;
	int		x;
	int		y;
	char	**map;
	char	**map_copy;
	int		count;
}			t_game;

void		ft_error(t_game *game, char *text, int error);
int			ft_open_file(char *map_name);
void		ft_init_game(t_game *game);
void		ft_star_game(t_game *game);
void		ft_check_wall(t_game *game);
void		ft_create_maps(char *map_name, t_game *game);
void		ft_paint_map(t_game *game);
void		ft_get_xpm(t_game *game);
void		ft_hook(t_game *game);
void		ft_move(t_game *game, int x, int y);
void		ft_put_img(t_game *game, int x, int y, void *img);
int			ft_equal(t_game *game, int x, int y, char letter);
void		ft_destroy(t_game *game);
void		ft_write_moves(t_game *game);
int			count_lines(t_game *game);
int			count_columns(t_game *game);
void		define_px_py_position(char **array, t_game *game);
void		define_ex_ey_position(char **array, t_game *game);
void		check_map(t_game *game);
void		game_xto_px_game_yto_yx(t_game *game);
void		ft_finishable_map(t_game *game, int x, int y);
void		check_pec(t_game *game);
void		check_name(char *name);
void		game_x_to_i(t_game *game, int i, int u);
void		repair_buffer1(int fd, char *buffer);
void		repair_buffer2(int fd, char *buffer);
void		repair_buffer3(int fd, char *buffer);

#endif