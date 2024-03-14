/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:40 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/14 18:24:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_var(t_game *game)
{
	game->collectff = 0;
	game->ncollect = 0;
	game->nexit = 0;
	game->nplayers = 0;
	game->invalid_char = 0;
}

t_game	*init_game(char *file)
{
	t_game	*game;
	int		i;
	int		j;

	j = -1;
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = fill_map(file);
	game->mapcopy = fill_map(file);
	player_pos(game);
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = count_column(game->map);
	init_var(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64 + 200, \
	game->map_height * 64, "So_Long");
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
			count_letter(game, game->map[j][i]);
	}
	return (game);
}

int	check_new_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (0);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	printf("\n************************************\n");
	return (1);
}

void	exit_helper2(t_game *game, int status)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit (status);
}

void	exit_helper(t_game *game, int status)
{
	int	j;

	if (game->map)
	{
		j = 0;
		while (game->map[j])
			free(game->map[j++]);
		free(game->map);
	}
	if (game->mapcopy)
	{
		j = 0;
		while (game->mapcopy[j])
			free(game->mapcopy[j++]);
		free(game->mapcopy);
	}
	if (game->img)
	{
		j = 0;
		while (j < IMGCNT)
			mlx_destroy_image(game->mlx, game->img[j++]);
		free(game->img);
	}
	exit_helper2(game, status);
}
