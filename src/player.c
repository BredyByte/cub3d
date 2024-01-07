/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:05:01 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/07 23:26:12 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_info *info)
{
	int	i;
	int	j;

	info->player->pos_x = 160;
	info->player->pos_y = 80;
	info->player->width = 10;
	info->player->height = 10;
	info->player->walk_speed = 0.05;
	info->player->rot_speed = 0.05 * (M_PI / 180);
	info->player->p_img = (mlx_image_t *)malloc(sizeof(mlx_image_t));
	info->player->p_img = mlx_new_image(info->mlx, PLAYER_SIZE, PLAYER_SIZE);
	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			mlx_put_pixel(info->player->p_img, j, i, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
	mlx_image_to_window(info->mlx, info->player->p_img, info->player->pos_x, info->player->pos_y);
}
