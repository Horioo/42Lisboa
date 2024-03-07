/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:35:06 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/03/07 17:35:02 by ajorge-p         ###   ########.fr       */
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
    
    j = 0;
    while(game->map[j])
    {
        i = 0;
        while(game->map[j][i])
        {
            if(game->map[j][i] == 'P')
            {
                printf("Player\n");
                mlx_put_image_to_window(game->mlx, game->win, game->img[0], i * 64, j * 64);
                printf("Player saida\n");
            }
            else if(game->map[j][i] == 'E')
            {
                printf("Exit\n");
                if(game->nCollect == 0)
                    mlx_put_image_to_window(game->mlx, game->win, game->img[4], i * 64, j * 64);
                else
                    mlx_put_image_to_window(game->mlx, game->win, game->img[5], i * 64, j * 64);
                printf("Exit saida\n");
            }
            else if(game->map[j][i] == '1')
            {
                printf("Parede\n");
                mlx_put_image_to_window(game->mlx, game->win, game->img[3], i * 64, j * 64);
                printf("Parede saida\n");
            }
            else if(game->map[j][i] == 'C')
            {
                printf("Collect\n");
                mlx_put_image_to_window(game->mlx, game->win, game->img[2], i * 64, j * 64);
                printf("Collect saida\n");
            }
            else if(game->map[j][i] == '0')
            {
                printf("Chao\n");
                mlx_put_image_to_window(game->mlx, game->win, game->img[1], i * 64, j * 64);
                printf("Chao Saida\n");
            }
            i++;
        }
        j++;
    }
}
