/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:17:40 by arsbadal          #+#    #+#             */
/*   Updated: 2023/07/08 19:17:54 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*free_single(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

void	*free_double(void ***addr)
{
	int	i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_single((void *)&(*addr)[i]);
			i++;
		}
		free_single((void *)&(*addr));
	}
	return (0);
}

void	free_all_mem(t_game *game)
{
	free_double((void *)&game->map);
	free_single((void *)&game->options->path_to_ea);
	free_single((void *)&game->options->path_to_so);
	free_single((void *)&game->options->path_to_we);
	free_single((void *)&game->options->path_to_no);
	free_single((void *)&game->options);
	free_single((void *)&game->map_t.ea);
	free_single((void *)&game->map_t.so);
	free_single((void *)&game->map_t.no);
	free_single((void *)&game->map_t.we);
	free_single((void *)&game->map_t.door);
	free_single((void *)&game->sp.soldier_1);
	free_single((void *)&game->sp.soldier_2);
	free_single((void *)&game->sp.soldier_3);
	free_single((void *)&game->sp.soldier_4);
	free_single((void *)&game->sp.soldier_5);
	free_single((void *)&game->sp.soldier_6);
	free_single((void *)&game->sp.soldier_7);
	free_single((void *)&game);
}
