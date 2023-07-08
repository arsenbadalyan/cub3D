/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:17:36 by arsbadal          #+#    #+#             */
/*   Updated: 2023/07/08 19:17:36 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	catch_error(t_game *game, const char *msg)
{
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	free_all_mem(game);
	exit(EXIT_FAILURE);
}
