/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:16:16 by arsbadal          #+#    #+#             */
/*   Updated: 2023/07/08 19:16:17 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_full_line(char *line)
{
	size_t	i;

	i = 0;
	if (!line || !line[0])
		return (EXIT_SUCCESS);
	while (line[i])
	{
		if (!ft_strchr(WHITE_SPACE, line[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
	Checking file extention
*/
int	is_correct_ext(t_game *game, char *path, char *check)
{
	char	**ext;
	size_t	size;
	int		status;

	status = EXIT_SUCCESS;
	ext = ft_split(path, '.');
	if (!ext)
		catch_error(game, E_NOMEM);
	size = get_2d_array_length((void **)ext);
	if (ft_strcmp(ext[size - 1], check))
		status = EXIT_FAILURE;
	free_double((void *)&ext);
	return (status);
}
