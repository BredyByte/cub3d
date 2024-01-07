/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:49:16 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/07 22:26:18 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include "cub3d.h"

typedef struct s_map
{
	mlx_image_t	*m_img;
	int			width;
	int			height;
	int			pos_x;
	int			pos_y;
	int			**map;
}				t_map;

typedef struct s_player
{
	mlx_image_t	*p_img;
	int			width;
	int			height;
	int			pos_x;
	int			pos_y;
	int			dir_x;
	int			dir_y;
	float		walk_speed;
	float		rot_speed;
}				t_player;

typedef struct s_info
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_player	*player;
	t_map		*map;
	char		*no_txt_loc;
	char		*so_txt_loc;
	char		*we_txt_loc;
	char		*ea_txt_loc;
	int			f_color;
	int			c_color;
	int			width;
	int			height;
	int			**matrix_map;
}				t_info;

#endif