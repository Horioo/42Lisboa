/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/13 17:57:28 by ajorge-p         ###   ########.fr       */
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
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

# define IMGCNT 11


/* Map Check */

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_game
{
    void *mlx;
	void *win;
	char			**map;
	char			**mapcopy;
	int				player_x;
	int				player_y;
	int				map_height; //size.y
	int				map_width; //size.x
	void            **img;
	void			*animation;
	int				nCollect;
	int				collectff;
	int				nPlayers;
	int				nExit;
	int				invalid_char;
}				t_game;


int 		checkber(char *file);
int 		ft_strcmp(char *s1, char *s2);
void		player_pos(t_game *game);
int			colum_maps(char *file);
char 		**fill_map(char *file);
void		print_map(char **map);
t_game		*init_game(char *file);
int			check_valid_map(t_game *game);
int			is_square(char **map);
void		flood_fill(t_game *game, int x, int y);
int 		closed_walls(t_game *game);
int			count_column(char **map);
void		count_letter(t_game *game, char c);
void		errormsg(t_game *game, char *msg, int status);
int		    close_game(t_game *game);
int 	    key_press(int keycode, t_game *game);
int         ft_compare(char *s, char c);
void        put_map_visual(t_game *game);
void        moves(int x, int y, t_game *game);
int         check_moves(t_game *game, int y, int x);
void		exit_helper2(t_game *game, int status);
void		exit_helper(t_game *game, int status);
void		print_all(t_game *game);
int			enemy_animation(t_game *game);
void		enemy_move(t_game *game);
void		init_images(t_game *game);

#endif