/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:40 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/11 17:38:27 by ajorge-p         ###   ########.fr       */
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
	else if(c == '0' || c == '1')
		;
	else if (c == '\n')
		;
	else
	{
		printf("Invalid Char = %c\n", c);
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

t_coord		player_pos(char **map)
{
	t_coord	*ret;
	int i;
	int j;
	
	j = 0;
	ret = malloc(sizeof(t_coord));
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if(map[j][i] == 'P')
			{
				ret->x = i * 64;
				ret->y = j * 64;
				return (*ret);
			}
			i++;
		}
		j++;
	}
	return (*ret);
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
	game->player = player_pos(game->map);
	game->size.x = ft_strlen(game->map[0]);
	game->size.y = count_column(game->map);
	game->collectff = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->size.x * 64, game->size.y * 64, "So_Long");
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

void	flood_fill(t_game *game, t_coord size, t_coord begin)
{
	if(!game->mapcopy)
		return ;
	if(game->mapcopy[begin.x][begin.y] == '1' || begin.x > size.y || begin.y > size.x)
		return ;
	if(game->mapcopy[begin.x][begin.y] == 'E' )
	{
		if(game->collectff == game->nCollect)
		{
			game->mapcopy[begin.x][begin.y] = '1';	
			return ;
		}
		return ;
	}
	if(game->mapcopy[begin.x][begin.y] == 'C')
		game->collectff++;
	game->mapcopy[begin.x][begin.y] = '1';
	flood_fill(game, size, (t_coord){begin.x + 1, begin.y});
	flood_fill(game, size, (t_coord){begin.x - 1, begin.y});
	flood_fill(game, size, (t_coord){begin.x, begin.y + 1});
	flood_fill(game, size, (t_coord){begin.x, begin.y - 1});
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
	if(!ft_compare(game->map[game->size.y - 1], '1'))
		return (0);
	while(game->map[cnt][0])
	{
		if(game->map[cnt][0] != '1' || game->map[cnt][game->size.x - 1] != '1')
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
			if(map[j][i] == 'C' || map[j][i] == 'E')
				return (0);
			i++;
		}
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
	flood_fill(game, game->size, (t_coord){game->player.x / 64, game->player.y / 64});
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
	printf("Window Limpo\n");
	if(game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	printf("MLX Limpo\n");
	exit (status);
}

void	exit_helper(t_game *game, int status)
{
	int j;

	if(game->map)
	{
		j = 0;
		while(game->map[j++])
			free(game->map[j]);
		free(game->map);
	}
	printf("Map Limpo\n");
	j = 0;
	if(game->mapcopy)
	{
		j = 0;
		while(game->mapcopy[j++])
			free(game->mapcopy[j]);
		free(game->mapcopy);
	}
	printf("MapCopy Limpo\n");
	j = -1;
	if(game->img)
	{
		while(game->img[++j])
			mlx_destroy_image(game->mlx, game->img[j]);
		free(game->img);
	}
	printf("Img Limpo\n");
	exit_helper2(game, status);
}

void	errormsg(t_game *game, char *msg, int status)
{
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
