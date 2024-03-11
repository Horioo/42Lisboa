/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:06 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/11 16:31:43 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void init_images(t_game *game, int i)
{
    game->img = malloc(sizeof(void *) * IMGCNT);
    if(!game->img)
        return ;
    game->img[0] = mlx_xpm_file_to_image(game->mlx, "pixel_art/player.xpm", &i, &i);
    game->img[1] = mlx_xpm_file_to_image(game->mlx, "pixel_art/floor.xpm", &i, &i);
    game->img[2] = mlx_xpm_file_to_image(game->mlx, "pixel_art/collect.xpm", &i, &i);
    game->img[3] = mlx_xpm_file_to_image(game->mlx, "pixel_art/wall.xpm", &i, &i);
    game->img[4] = mlx_xpm_file_to_image(game->mlx, "pixel_art/Portal_Close.xpm", &i, &i);
    game->img[5] = mlx_xpm_file_to_image(game->mlx, "pixel_art/Portal_Open.xpm", &i, &i);    
    game->img[6] = mlx_xpm_file_to_image(game->mlx, "pixel_art/enemy.xpm", &i, &i);
}

void put_map_visual(t_game *game)
{
    int i;
    int j;
    int k;
    
    j = -1;
    k = 0;
    init_images(game, k);
    while(game->map[++j])
    {
        i = -1;
        while(game->map[j][++i])
        {
            mlx_put_image_to_window(game->mlx, game->win, game->img[1], i * 64, j * 64);
            if(game->map[j][i] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img[0], i * 64, j * 64);
            else if(game->map[j][i] == 'E')
            {
                if(game->nCollect == 0)
                    mlx_put_image_to_window(game->mlx, game->win, game->img[5], i * 64, j * 64);
                else
                    mlx_put_image_to_window(game->mlx, game->win, game->img[4], i * 64, j * 64);
            }
            else if(game->map[j][i] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img[3], i * 64, j * 64);
            else if(game->map[j][i] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img[2], i * 64, j * 64);
            else if(game->map[j][i] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img[1], i * 64, j * 64);
        }
    }
}
