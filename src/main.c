/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:27:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 11:53:54 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parser	*parser;

	if (argc < 2)
		return (put_usage(), 1);
	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (put_error(E_MEMORY, 0), 1);
	map_parsing(parser, argv[1]);
	dbg_file_data(parser);
	free_parser_data(parser);
	return (0);
}
