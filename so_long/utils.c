/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:40 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/13 18:54:38 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int checkber(char *file)
{
	int len;

	len = ft_strlen(file);
	if(len > 4 && ft_strcmp(file + len - 4, ".ber") == 0)
		return(1);
	return (0);
}

int	colum_maps(char *file)
{
	int cnt;
	char *row;
	int fd;
	
	cnt = 0;
	fd = open(file, O_RDONLY);
	row = get_next_line(fd);
	while(row)
	{
		row = get_next_line(fd);
		cnt++;
	}
	close(fd);
	return (cnt);
}

char **fill_map(char *file)
{
	int cnt;
	char **map;
	char *row;
	int line;
	int fd;

	cnt = colum_maps(file);
	map = malloc(sizeof(char *) * (cnt + 1));
	row = get_next_line(-1);
	fd = open(file, O_RDONLY);
	row = get_next_line(fd);
	line = 0;
	while(row)
	{
		map[line++] = ft_strtrim(row, "\n");
		row = get_next_line(fd);
	}
	row = get_next_line(-1);
	map[line] = NULL;
	return (map);
}

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("\n***********************************\n");
	ft_printf("\t\tMAP\n");
	ft_printf("***********************************\n");
	while(map[i])
	{
		while(map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
	ft_printf("***********************************\n");
}

void	count_letter(t_game *game, char c)
{
	if(c == 'C')
		game->nCollect++;
	else if(c == 'E')
		game->nExit++;
	else if(c == 'P')
		game->nPlayers++;
	else if(c == '0' || c == '1' || c == 'X')
		;
	else if (c == '\n')
		;
	else
	{
		ft_printf("Invalid Char = %c\n", c);
		game->invalid_char = 1;
	}
}


int		count_column(char **map)
{
	int cnt;

	cnt = 0;
	while(map[cnt])
		cnt++;
	return (cnt);
}

void		player_pos(t_game *game)
{
	int i;
	int j;
	
	j = 0;
	while(game->map[j])
	{
		i = 0;
		while(game->map[j][i])
		{
			if(game->map[j][i] == 'P')
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

t_game	*init_game(char *file)
{
	t_game *game;
	int i;
	int j;

	j = -1;
	game = malloc(sizeof(t_game));
	if(!game)
		return (NULL);
	game->map = fill_map(file);
	game->mapcopy = fill_map(file);
	player_pos(game);
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = count_column(game->map);
	game->collectff = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64, game->map_height * 64, "So_Long");
	while(game->map[++j])
	{
		i = -1;
		while(game->map[j][++i])
			count_letter(game, game->map[j][i]);
	}
	return (game);
}

int	is_square(char **map)
{
	int mover;
	int rows;

	rows = ft_strlen(map[0]);
	mover = 0;
	while(map[mover])
	{
		if(ft_strlen(map[mover]) != rows)
			return (0);
		mover++;
	}
	return (1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if(!game->mapcopy || x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if(game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == 'X')
		return ;
	if(game->mapcopy[y][x] == 'E')
	{
		if(game->collectff == game->nCollect)
		{
			game->mapcopy[y][x] = '1';
			return ;
		}
		return ;
	}
	if(game->mapcopy[y][x] == 'C')
		game->collectff++;
	game->mapcopy[y][x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

int ft_compare(char *s, char c)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int closed_walls(t_game *game)
{
	int cnt;

	cnt = 0;
	if(!ft_compare(game->map[0], '1'))
		return (0);
	if(!ft_compare(game->map[game->map_height - 1], '1'))
		return (0);
	while(game->map[cnt][0])
	{
		if(game->map[cnt][0] != '1' || game->map[cnt][game->map_width - 1] != '1')
			return 0;
		cnt++;
		if(!game->map[cnt])
			break;
	}
	return 1;
}
int	check_new_map(char **map)
{
	int i;
	int j;
	
	j = 0;
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if(map[j][i] == 'C')
				return (0);
			i++;
		}
		printf("\n");
		j++;
	}
	return (1);	printf("\n************************************\n");
}
int	check_valid_map(t_game *game)
{
	if(!is_square(game->map))
		return 0;
	if(!closed_walls(game))
		return 0;
	if(game->nPlayers > 1 || game->nExit > 1 || game->nCollect < 1)
		return 0;
	//printf("Valores de:\nSize Y = %d\nX = %d\nPlayer Y = %d\nX = %d\n", game->map_height, game->map_width, game->player_y, game->player_x);
	printf("Width = %d\nHeight = %d\nPlayer x = %d\nPlayer y = %d\n", game->map_width, game->map_height, game->player_x, game->player_y);
	flood_fill(game, game->player_x / 64, game->player_y / 64);
	print_map(game->mapcopy);
	if(!check_new_map(game->mapcopy))
		errormsg(game, "Problems on Flood Fill\n", 1);
	return 1;
}

void	free_game(t_game *game)
{
	if(game->map)
		free(game->map);
}

void	exit_helper2(t_game *game, int status)
{
	if(game->win)
		mlx_destroy_window(game->mlx, game->win);
	if(game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit (status);
}

void	exit_helper(t_game *game, int status)
{
	int j;

	if(game->map)
	{
		j = 0;
		while(game->map[j])
			free(game->map[j++]);
		free(game->map);
	}
	if(game->mapcopy)
	{
		j = 0;
		while(game->mapcopy[j])
			free(game->mapcopy[j++]);
		free(game->mapcopy);
	}
	if(game->img)
	{
		j = 0;
		while(j < IMGCNT)
			mlx_destroy_image(game->mlx, game->img[j++]);
		free(game->img);
	}
	exit_helper2(game, status);
}

void	errormsg(t_game *game, char *msg, int status)
{
	if(!game)
		return ;
	if(status)
		ft_printf("Error - ");
	ft_printf("%s\n", msg);
	exit_helper(game, status);
}

int		close_game(t_game *game)
{
	errormsg(game, "Bye Bye >:)", 0);
	return (0);
}
