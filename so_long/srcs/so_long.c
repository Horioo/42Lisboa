/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/15 15:14:00 by ajorge-p         ###   ########.fr       */
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

void	print_error(char *str)
{
	ft_printf("%s", str);
	exit (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		print_error("Error - Error on Arguments\n");
	if (!checkber(av[1]))
		print_error("Error - Error on .ber\n");
	if (open(av[1], O_RDONLY) == -1)
		print_error("Error - Invalid Map File\n");
	game = init_game(av[1]);
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
