/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:54:29 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/15 15:19:10 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	moves(int x, int y, t_game *game)
{
	static int	steps;
	char		*v_itoa;
	int			i;

	game->map[game->player_y / 64][game->player_x / 64] = '0';
	mlx_put_image_to_window(game->mlx, game->win, \
	game->img[1], game->player_x, game->player_y);
	game->player_x = x * 64;
	game->player_y = y * 64;
	game->map[y][x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, \
	game->img[0], game->player_x, game->player_y);
	steps++;
	v_itoa = ft_itoa(steps);
	i = -1;
	while (++i <= 100)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img[11], (game->map_width * 64 + 100) + i, 0);
	}
	mlx_string_put(game->mlx, game->win, \
	game->map_width * 64 + 100, 10, 0xFFFF00, v_itoa);
	free(v_itoa);
	ft_printf("Steps = %d", steps);
}

int	check_moves(t_game *game, int y, int x)
{
	if (x < 0 || y < 0)
		return (0);
	if (game->map[x][y] == '1')
		return (0);
	if (game->map[x][y] == 'C')
	{
		game->ncollect--;
		game->map[x][y] = '0';
	}
	if (game->map[x][y] == 'E')
	{
		if (game->ncollect == 0)
			errormsg(game, \
			"Congratulations you just defeated your First Dungeon\n", 0);
		return (0);
	}
	if (game->map[x][y] == 'X')
		errormsg(game, "The Wolf got you, the System can't Help\n", 0);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	int	x;
	int	y;

	if (keycode == ESC)
		close_game(game);
	if (keycode != DOWN && keycode != UP && keycode != LEFT && keycode != RIGHT)
		return (1);
	x = game->player_x / 64 + ((keycode == RIGHT) - (keycode == LEFT));
	y = game->player_y / 64 + ((keycode == DOWN) - (keycode == UP));
	if (check_moves(game, x, y))
	{
		moves(x, y, game);
		put_map_visual(game);
		print_map(game->map);
	}
	return (0);
}

void	enemy_render(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'X')
			{
				mlx_put_image_to_window(game->mlx, game->win, \
				game->animation, i * 64, j * 64);
			}
			i++;
		}
		j++;
	}
}

int	enemy_animation(t_game *game)
{
	static int	animcount;
	static int	i_enemy = 6;

	if (animcount == 15000)
	{
		game->animation = game->img[i_enemy];
		enemy_render(game);
		i_enemy++;
		if (i_enemy > 10)
			i_enemy = 6;
		animcount = 0;
	}
	else
		animcount++;
	return (0);
}
