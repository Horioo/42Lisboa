/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:13:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/14 18:52:23 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

# define IMGCNT 12

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	char			**mapcopy;
	int				player_x;
	int				player_y;
	int				map_height;
	int				map_width;
	void			**img;
	void			*animation;
	int				ncollect;
	int				collectff;
	int				nplayers;
	int				nexit;
	int				invalid_char;
}				t_game;

/*			Error Handling		*/

int			checkber(char *file);
int			ft_strcmp(char *s1, char *s2);
int			check_valid_map(t_game *game);
int			is_square(char **map);
void		flood_fill(t_game *game, int x, int y);
int			closed_walls(t_game *game);
int			ft_compare(char *s, char c);
int			check_new_map(char **map);

/*			Init Game			*/

t_game		*init_game(char *file);
void		player_pos(t_game *game);
int			colum_maps(char *file);
char		**fill_map(char *file);
void		print_map(char **map);
int			count_column(char **map);
void		count_letter(t_game *game, char c);
void		init_images(t_game *game);
void		put_map_visual(t_game *game);
void		put_map_visual_2(t_game *game, int j, int i);

/*			Close Game			*/

void		errormsg(t_game *game, char *msg, int status);
int			close_game(t_game *game);
void		exit_helper2(t_game *game, int status);
void		exit_helper(t_game *game, int status);

/*			Events				*/

int			key_press(int keycode, t_game *game);
void		moves(int x, int y, t_game *game);
int			check_moves(t_game *game, int y, int x);
int			enemy_animation(t_game *game);

#endif