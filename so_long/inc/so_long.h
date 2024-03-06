/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/06 15:54:32 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../mlx_linux/mlx.h"

# define ESC 65307

# define LEFT 0xff51
# define UP 0xff52
# define RIGHT 0xff53
# define DOWN 0xff54


/* Map Check */

typedef struct s_date{
	void *img;
	char *addr;
	int 	bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_game
{
	char			**map;
	char			**mapcopy;
	t_coord			player;
	t_coord			size;
	t_data			img;
	int				nCollect;
	int				collectff;
	int				nPlayers;
	int				nExit;
	int				invalid_char;
}				t_game;

typedef struct s_vars {
	void *mlx;
	void *win;
}				t_vars;


int 		checkber(char *file);
int 		ft_strcmp(char *s1, char *s2);
int			colum_maps(char *file);
char 		**fill_map(char *file);
void		print_map(char **map);
t_game		*init_game(char *file);
int			check_valid_map(t_game *game);
int			is_square(char **map);
void		flood_fill(t_game *game, t_coord size, t_coord begin);
int 		closed_walls(t_game *game);
int			count_column(char **map);
void			count_letter(t_game *game, char c);
void	errormsg(t_game *game, char *str);
void	pixel_put(t_data *data, int x, int y, int color);
int		close_game(t_vars *vars);
int 	key_press(int keycode, t_vars *vars);
int ft_compare(char *s, char c);
void put_map_visual(t_game *game, t_vars *vars);

#endif