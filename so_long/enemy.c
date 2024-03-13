/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/13 17:29:28 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	enemy_render(t_game *game)
{
	int i;
	int j;

	j = 0;
	while(game->map[j])
	{
		i = 0;
		while(game->map[j][i])
		{
			if(game->map[j][i] == 'X')
				mlx_put_image_to_window(game->mlx, game->win, game->animation, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

int	enemy_animation(t_game *game)
{
	static int	animcount;
	static int	i_enemy = 6;
	
	
	if(animcount  == 15000)
	{
		game->animation = game->img[i_enemy];
		enemy_render(game);
		i_enemy++;
		if(i_enemy > 10)
			i_enemy = 6;
		animcount = 0;
	}
	else
		animcount++;
	return (0);
}