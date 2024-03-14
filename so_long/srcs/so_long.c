/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/14 17:53:21 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	errormsg(t_game *game, char *msg, int status)
{
	if (!game)
		return ;
	ft_printf("\n*************\n* End Game  *\n*************\n\n");
	if (status)
		ft_printf("Error - ");
	ft_printf("%s\n", msg);
	exit_helper(game, status);
}

int	close_game(t_game *game)
{
	errormsg(game, "Bye Bye >:)", 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac == 2)
	{
		game = init_game(av[1]);
		if (!checkber(av[1]))
			errormsg(game, "Error on .ber", 1);
		if (game->invalid_char == 1)
			errormsg(game, "Invalid Char\n", 1);
		if (!check_valid_map(game))
			errormsg(game, "Problem with the Map\n", 1);
		print_map(game->map);
		ft_printf("\n*************\n*Init Window*\n*************\n");
		init_images(game);
		put_map_visual(game);
		mlx_string_put(game->mlx, game->win, game->map_width * 64 + 10, 10, \
		0xFFFF00, "Steps Counter:");
		mlx_hook(game->win, 17, 0, close_game, game);
		mlx_key_hook(game->win, key_press, game);
		mlx_loop_hook(game->mlx, enemy_animation, game);
		mlx_loop(game->mlx);
	}
	errormsg(game, "Error on Arguments\n", 1);
}
