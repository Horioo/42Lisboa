/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:54:29 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/07 17:34:31 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

// void    moves(int x, int y, int keycode, t_game *game)
// {
    
// }


int check_moves(t_game *game, int x, int y)
{
    //Verificar se e parede (1), se e Collectable (C), se e Exit (E), Bonus (Se e enemy (W))
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
            errormsg(game, "Congratulations you just defeated the Monarchs");
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
    x = game->player.x / 64 + ((keycode == LEFT) - (keycode == RIGHT));
    y = game->player.y / 64 + ((keycode == DOWN) - (keycode == UP));
    //if(check_moves(game, x, y))
        //moves(x, y, keycode, game);
	return (0);
}