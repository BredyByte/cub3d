/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:05:01 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/07 22:34:13 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		info->player->pos_x -= STEP;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		info->player->pos_y += STEP;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		info->player->pos_x += STEP;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		info->player->pos_y -= STEP;
	info->player->p_img->instances[0].x = info->player->pos_x;
	info->player->p_img->instances[0].y = info->player->pos_y;
}

void	play_game(t_info *info)
{
	info->width = WIN_W_SIZE;
	info->height = WIN_H_SIZE;
	info->mlx = mlx_init(info->width, info->height, APP_NAME, false);
	info->g_img = mlx_new_image(info->mlx, info->width, info->height);
	mlx_image_to_window(info->mlx, info->g_img, 0, 0);
	init_map(info);
	init_player(info);
	mlx_key_hook(info->mlx, &my_keyhook, info);
	printf("player\n");
	mlx_loop(info->mlx);
}
