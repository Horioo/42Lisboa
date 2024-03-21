/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/15 14:48:00 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	colum_maps(char *file)
{
	int		cnt;
	char	*row;
	int		fd;

	cnt = 0;
	fd = open(file, O_RDONLY);
	row = get_next_line(fd);
	while (row)
	{
		free(row);
		row = get_next_line(fd);
		cnt++;
	}
	free(row);
	close(fd);
	return (cnt);
}

char	**fill_map(char *file)
{
	int		cnt;
	char	**map;
	char	*row;
	int		line;
	int		fd;

	cnt = colum_maps(file);
	map = malloc(sizeof(char *) * (cnt + 1));
	row = get_next_line(-1);
	fd = open(file, O_RDONLY);
	row = get_next_line(fd);
	line = 0;
	while (row)
	{
		map[line++] = ft_strtrim(row, "\n");
		free(row);
		row = get_next_line(fd);
	}
	free(row);
	map[line] = NULL;
	close(fd);
	return (map);
}

void	count_letter(t_game *game, char c)
{
	if (c == 'C')
		game->ncollect++;
	else if (c == 'E')
		game->nexit++;
	else if (c == 'P')
		game->nplayers++;
	else if (c == '0' || c == '1' || c == 'X')
		;
	else if (c == '\n')
		;
	else
	{
		ft_printf("Invalid Char = %c\n", c);
		game->invalid_char = 1;
	}
}

int	count_column(char **map)
{
	int	cnt;

	cnt = 0;
	while (map[cnt])
		cnt++;
	return (cnt);
}

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
			{
				game->player_x = i * 64;
				game->player_y = j * 64;
				return ;
			}
			i++;
		}
		j++;
	}
}
