/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:54:29 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/11 17:17:30 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void    moves(int x, int y, t_game *game)
{
    static int steps;
	
	if(game->map[y][x] == 'E')
		return ;
	game->map[game->player.y / 64][game->player.x / 64] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->img[1], game->player.x, game->player.y);
    game->player.x = x * 64;
    game->player.y = y * 64;
	game->map[y][x] = 'P';
    mlx_put_image_to_window(game->mlx, game->win, game->img[0], game->player.x, game->player.y);
    steps++;
	mlx_string_put(game->mlx, game->win, 400, 10, 0xFFFFFF, "Steps Counter:");
	ft_printf("Steps = %d", steps);
}


int check_moves(t_game *game, int y, int x)
{
    if(x < 0 || y < 0)
        return (0);
    if(game->map[x][y] == '1')
        return (0);
    if(game->map[x][y] == 'C')
    {
        game->nCollect--;
        game->map[x][y] = '0';
    }
    if(game->map[x][y] == 'E')
    {
        if(game->nCollect == 0)
            errormsg(game, "Congratulations you just defeated the Monarchs", 0);
    }
    return (1);
}

int key_press(int keycode, t_game *game)
{
    int x;
    int y;
    
	if(keycode == ESC)
		close_game(game);
    if(keycode != DOWN && keycode != UP && keycode != LEFT && keycode != RIGHT)
        return (1);
    x = game->player.x / 64 + ((keycode == RIGHT) - (keycode == LEFT));
    y = game->player.y / 64 + ((keycode == DOWN) - (keycode == UP));
    if(check_moves(game, x, y))
	{
        moves(x, y, game);
	}
	put_map_visual(game);
	print_map(game->map);
	return (0);
}
