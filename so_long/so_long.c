/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/07 17:33:15 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	print_game(t_game *game)
{
	printf("Width = %d\nHeight = %d\nnCollect = %d\nnPlayers = %d\nnExit = %d\n", game->size.x, game->size.y, game->nCollect, game->nPlayers, game->nExit);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		t_game *game;
		int color = 0x00FF0000;
		
		//check if map is .ber
		if(!checkber(av[1]))
			exit(1);
		//Init game with Map;
		game = init_game(av[1]);
		if(game->invalid_char == 1)
			errormsg(game, "Invalid Char - Error\n");

		print_game(game);
		//View Map
		if(!check_valid_map(game))
			errormsg(game, "Problem with the Map - Error \n");
		print_map(game->map);
		printf("\n*************\nInit Window\n*************\n");
		//Passar isto tudo para uma funcao a parte:    ft_init_visual(game);
		printf("Teste\n");
		put_map_visual(game);
		mlx_string_put(game->mlx, game->win, 400, 10, color, "Steps Counter:");
		mlx_hook(game->win, 17, 0, close_game, game);
		mlx_key_hook(game->win, key_press, game);
		mlx_loop(game->mlx);
		printf("\n*************\nEnd Game\n*************\n");
	}
}