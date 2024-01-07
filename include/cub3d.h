/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/07 21:51:09 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../assets/MLX42/include/MLX42/MLX42.h"
# include "../assets/libft/include/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "cub3d_structs.h"
# include "cub3d_values.h"


void	put_usage(t_info *info);
void	put_error(char *str);

int		check_map(t_info *info, int fd);
int		check_map_extension(char *map);

// get map data
int		get_texture(char *line, t_info *info);
int		get_color(char *line, t_info *info);


// play game
void	play_game(t_info *info);

// player
void	init_player(t_info *info);

// map
void	init_map(t_info *info);

#endif
