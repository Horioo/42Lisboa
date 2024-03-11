/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/11 17:31:49 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

// void	print_game(t_game *game)
// {
// 	printf("Width = %d\nHeight = %d\nnCollect = %d\nnPlayers = %d\nnExit = %d\n", game->size.x, game->size.y, game->nCollect, game->nPlayers, game->nExit);
// }

int main(int ac, char **av)
{
	t_game *game;
	
	game = NULL;
	if(ac == 2)
	{
		if(!checkber(av[1]))
			errormsg(game, "Error on .ber", 1);
		game = init_game(av[1]);
		if(game->invalid_char == 1)
			errormsg(game, "Invalid Char\n", 1);
		if(!check_valid_map(game))
			errormsg(game, "Problem with the Map\n", 1);
		print_map(game->map);
		printf("\n*************\nInit Window\n*************\n");
		put_map_visual(game);
		mlx_hook(game->win, 17, 0, close_game, game);
		mlx_key_hook(game->win, key_press, game);
		mlx_loop(game->mlx);
		printf("\n*************\nEnd Game\n*************\n");
	}
	errormsg(game, "Error on Arguments\n", 1);
}
