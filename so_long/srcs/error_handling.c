/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:34:00 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/15 15:21:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_valid_map(t_game *game)
{
	if (!is_square(game->map))
		errormsg(game, "Map is not Square\n", 1);
	if (!closed_walls(game))
		errormsg(game, "Map is not closed by Walls\n", 1);
	if (game->nplayers > 1)
		errormsg(game, "Number of Players is more than 1\n", 1);
	if (game->nexit > 1)
		errormsg(game, "Number of Exits is more than 1\n", 1);
	if (game->ncollect < 1)
		errormsg(game, "Number of Collectables is less than 1\n", 1);
	flood_fill(game, game->player_x / 64, game->player_y / 64);
	if (!check_new_map(game->mapcopy))
		errormsg(game, "Problems on Flood Fill\n", 1);
	return (1);
}

int	is_square(char **map)
{
	int	mover;
	int	rows;

	rows = ft_strlen(map[0]);
	mover = 0;
	while (map[mover])
	{
		if (ft_strlen(map[mover]) != rows)
			return (0);
		mover++;
	}
	return (1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (!game->mapcopy || x < 0 || x >= game->map_width || y < 0 || \
	y >= game->map_height)
		return ;
	if (game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == 'X')
		return ;
	if (game->mapcopy[y][x] == 'E')
	{
		if (game->collectff == game->ncollect)
		{
			game->mapcopy[y][x] = '1';
			return ;
		}
		return ;
	}
	if (game->mapcopy[y][x] == 'C')
		game->collectff++;
	game->mapcopy[y][x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
