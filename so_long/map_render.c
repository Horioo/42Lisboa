/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:06 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/06 17:38:39 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void put_map_visual(t_game *game, t_vars *vars)
{
    int i;
    int j;
    int img_width;
    int img_height;
    char *path;
    
    j = 0;
    while(game->map[j])
    {
        i = 0;
        while(game->map[j][i])
        {
            if(game->map[j][i] == 'P')
            {
                path = "./pixel_art/player.xpm";
                game->img.img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, i * 76, j * 66);
            }
            else if(game->map[j][i] == 'E')
            {
                if(game->nCollect > 3)
                    path = "./pixel_art/Portal_Close.xpm";
                else
                    path = "./pixel_art/Portal_Open.xpm";
                game->img.img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, i * 64, j * 64);
            }
            else if(game->map[j][i] == '1')
            {
                path = "./pixel_art/wall.xpm";
                game->img.img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, i * 64, j * 64);
            }
            else if(game->map[j][i] == 'C')
            {
                path = "./pixel_art/collect.xpm";
                game->img.img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, i * 70, j * 66);
            }
            else if(game->map[j][i] == '0')
            {
                path = "./pixel_art/floor.xpm";
                game->img.img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, i * 64, j * 64);
            }
            i++;
        }
        j++;
    }
}
