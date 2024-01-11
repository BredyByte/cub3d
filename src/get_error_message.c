/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:31:52 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 10:04:10 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char	*get_error_message(enum e_ErrorCode code)
{
	if (code == E_MEMORY)
		return ("Error: Can't allocate memory");
	else if (code == E_OBLIG_DATA)
		return ("Error: Wrong obligatory data");
	else if (E_INVALID_FILE)
		return ("Error: Wrong passed file");
	else if (E_INVALID_MAP)
		return ("Error: Invalid map format");
	else
		return ("Unknown error");
}
