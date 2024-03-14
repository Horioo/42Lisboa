/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:35:23 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/14 17:57:26 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	closed_walls(t_game *game)
{
	int	cnt;

	cnt = 0;
	if (!ft_compare(game->map[0], '1'))
		return (0);
	if (!ft_compare(game->map[game->map_height - 1], '1'))
		return (0);
	while (game->map[cnt][0])
	{
		if (game->map[cnt][0] != '1' || \
		game->map[cnt][game->map_width - 1] != '1')
			return (0);
		cnt++;
		if (!game->map[cnt])
			break ;
	}
	return (1);
}

int	ft_compare(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	checkber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len > 4 && ft_strcmp(file + len - 4, ".ber") == 0)
		return (1);
	return (0);
}
