/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:16:56 by arsbadal          #+#    #+#             */
/*   Updated: 2023/07/08 19:16:56 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	trim_options(t_game *game, char **map);
static char	**fill_map(t_game *game, int fd);

/*
	Filling map in variable
*/
static char	**fill_map(t_game *game, int fd)
{
	char	*line;
	char	**map;

	line = NULL;
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = push_to_double_array(map, line);
		if (!map)
			catch_error(game, E_NOMEM);
	}
	return (map);
}

/*
	Opening file and fill it in variable
*/
static char	**open_map(t_game *game, char *map_name)
{
	char	**map;
	int		fd;

	if (is_correct_ext(game, map_name, "cub"))
		catch_error(game, E_WREXT);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		catch_error(game, E_WRPTH);
	map = fill_map(game, fd);
	close(fd);
	return (map);
}

static void	trim_options(t_game *game, char **map)
{
	size_t	i;
	size_t	size;
	char	*trimmed;

	i = 0;
	size = 0;
	while (map[i] && size < REQUIRED_IDS)
	{
		if (!is_full_line(map[i]) && ++i)
			continue ;
		trimmed = ft_strtrim(map[i], WHITE_SPACE);
		if (!trimmed)
			catch_error(game, E_NOMEM);
		free_single((void *)&map[i]);
		map[i] = trimmed;
		size++;
		i++;
	}
}

void	parse_controller(t_game *game, char **argv, int argc)
{
	int	status;

	if (argc != 1)
		catch_error(game, E_WRARG);
	game->map = open_map(game, argv[0]);
	if (!game->map)
		catch_error(game, E_WRCNF);
	trim_options(game, game->map);
	status = call_validator(game, game->map);
	if (status == EXIT_FAILURE)
		catch_error(game, E_WRCNF);
	else if (status == (EXIT_FAILURE + 1))
		catch_error(game, E_WRXPM);
}
