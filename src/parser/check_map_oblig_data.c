/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_oblig_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:33:06 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/10 20:37:23 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*str_get_color(char *line)
{
	char	**color;
	char	*c_line;
	int		*c_arr;
	int		i;

	i = 0;
	c_arr = (int *)malloc(sizeof(int) * 4);
	if (!c_arr)
		return (NULL);
	c_line = ft_str_del_space(line + 1);
	color = ft_split(c_line, ',');
	free(c_line);
	while (i < 3)
	{
		c_arr[i] = ft_atoi(color[i]);
		if (!ft_aredigits(color[i]) || c_arr[i] > 255 || c_arr[i] < 0)
			return (free(c_arr), ft_split_free(color), NULL);
		i++;
	}
	c_arr[i] = '\0';
	return (ft_split_free(color), c_arr);
}

static int	check_map_color(char *line, t_info *info)
{
	int	*c_arr;

	c_arr = str_get_color(line);
	if (c_arr != NULL)
	{
		if (line[0] == 'F')
			info->c_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 0);
		else if (line[0] == 'C')
			info->f_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 0);
	}
	else
		return (0);
	return (free(c_arr), 1);
}

static int	check_map_textures(char *line, t_info *info)
{
	int		fd;
	char	*texture_loc;

	texture_loc = ft_str_del_space(line + 2);
	fd = open(texture_loc, O_RDONLY);
	if (fd < 0)
		return (0);
	if (line[0] == 'N' && line[1] == 'O')
		info->no_txt_loc = texture_loc;
	else if (line[0] == 'S' && line[1] == 'O')
		info->so_txt_loc = texture_loc;
	else if (line[0] == 'W' && line[1] == 'E')
		info->we_txt_loc = texture_loc;
	else if (line[0] == 'E' && line[1] == 'A')
		info->ea_txt_loc = texture_loc;
	return (close(fd), 1);
}

int	check_map_oblig_data(t_info *info, int fd, char *line)
{
	while (!is_enough_info_oblig_data(info) && get_next_line(fd, &line))
	{
		if (is_texture_or_color(line, false))
		{
			if (!check_map_textures(line, info))
				return (0);
		}
		else if (is_texture_or_color(line, true))
		{
			if (!check_map_color(line, info))
				return (0);
		}
		free(line);
	}
	return (1);
}