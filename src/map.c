/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:50:35 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/07 23:33:52 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_info *info)
{
	int	i;
	int	j;

	info->map->width = info->width / MAP_RESIZE;
	info->map->height = info->height / MAP_RESIZE;
	info->map->m_img = (mlx_image_t *)malloc(sizeof(mlx_image_t));
	info->map->m_img = mlx_new_image(info->mlx, info->map->width, info->map->height);
	i = 0;
	while (i < info->map->height)
	{
		j = 0;
		while (j < info->map->width)
		{
			mlx_put_pixel(info->map->m_img, j, i, MAP_BACK_COLOR);
			j++;
		}
		i++;
	}
	mlx_image_to_window(info->mlx, info->map->m_img, MARGIN, MARGIN);
}
