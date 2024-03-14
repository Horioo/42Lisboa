/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:06 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/14 18:24:25 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_images_2(t_game *game, int i)
{
	game->img[7] = mlx_xpm_file_to_image(game->mlx, \
	"pixel_art/enemy_walk_1.xpm", &i, &i);
	game->img[8] = mlx_xpm_file_to_image(game->mlx, \
	"pixel_art/enemy_walk_2.xpm", &i, &i);
	game->img[9] = mlx_xpm_file_to_image(game->mlx, \
	"pixel_art/enemy_walk_3.xpm", &i, &i);
	game->img[10] = mlx_xpm_file_to_image(game->mlx, \
	"pixel_art/enemy_walk_4.xpm", &i, &i);
	game->img[11] = mlx_xpm_file_to_image(game->mlx, \
	"pixel_art/dark_cube.xpm", &i, &i);
}

void	init_images(t_game *game)
{
	int	i;

	i = 0;
	game->img = malloc(sizeof(void *) * IMGCNT);
	if (!game->img)
		return ;
	game->img[0] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/player.xpm", &i, &i);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/floor.xpm", &i, &i);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/collect.xpm", &i, &i);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/wall.xpm", &i, &i);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/Portal_Close.xpm", &i, &i);
	game->img[5] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/Portal_Open.xpm", &i, &i);
	game->img[6] = mlx_xpm_file_to_image(game->mlx, \
		"pixel_art/enemy_walk.xpm", &i, &i);
	init_images_2(game, i);
}

void	put_map_visual_2(t_game *game, int j, int i)
{
	if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img[2], i * 64, j * 64);
	else if (game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img[1], i * 64, j * 64);
	else if (game->map[j][i] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img[6], i * 64, j * 64);
	else if (game->map[j][i] == 'E')
	{
		if (game->ncollect == 0)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->img[5], i * 64, j * 64);
		else
			mlx_put_image_to_window(game->mlx, game->win, \
			game->img[4], i * 64, j * 64);
	}
}

void	put_map_visual(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			game->img[1], i * 64, j * 64);
			if (game->map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->img[0], i * 64, j * 64);
			else if (game->map[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->img[3], i * 64, j * 64);
			else
				put_map_visual_2(game, j, i);
		}
	}
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("\n***********************************\n");
	ft_printf("\t\tMAP\n");
	ft_printf("***********************************\n");
	while (map[i])
	{
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
	ft_printf("***********************************\n");
}
