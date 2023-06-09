/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:17:00 by arsbadal          #+#    #+#             */
/*   Updated: 2023/07/08 19:17:26 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Map validation rules
// in first is symbol valid
// every time save length of previous line (init value 0)
// allowed flags must be not first line, not last, not first column, not last
// allowed flags place must be smaller than line above, and line bottom
// above or bottom of allowed flags cannot be WHITE_SPACE
// left and right part of door must be wall

static void	get_borders(t_game *game, char **map, size_t *borders);
static int	check_flag(t_game *game, size_t *borders, size_t i, size_t j);
static int	validate_flags(t_game *game, char **map,
				size_t *borders, int unique);

/*
	Getting all map line lengths
*/
static void	get_borders(t_game *game, char **map, size_t *borders)
{
	size_t	i;

	i = 0;
	while (i < game->map_size)
	{
		borders[i] = ft_strlen(map[i]);
		i++;
	}
}

/*
	Check is flag in correct place
*/
static int	check_flag(t_game *game, size_t *borders, size_t i, size_t j)
{
	char		sym;
	static int	sprites;

	sym = game->map[i][j];
	if (sym == WALL_FLAG || ft_strchr(WHITE_SPACE, sym))
		return (EXIT_SUCCESS);
	if (sym == SPRITE_FLAG)
		sprites++;
	if (sprites > 1)
		return (EXIT_FAILURE);
	if (i == 0
		|| !game->map[i + 1]
		|| !game->map[i][j + 1]
		|| j >= borders[i - 1]
		|| j >= borders[i + 1]
		|| j == 0
		|| ft_strchr(WHITE_SPACE, game->map[i + 1][j])
		|| ft_strchr(WHITE_SPACE, game->map[i - 1][j])
		|| ft_strchr(WHITE_SPACE, game->map[i][j - 1])
		|| ft_strchr(WHITE_SPACE, game->map[i][j + 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	Validate flags if they are in wrong place
*/
static int	validate_flags(t_game *game, char **map,
	size_t *borders, int unique)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		if (!is_full_line(map[i]))
			return (EXIT_FAILURE);
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(UNIQUE_FLAGS, map[i][j]))
				unique++;
			else if (!ft_strchr(VALID_FLAGS, map[i][j]))
				return (EXIT_FAILURE);
			if (unique > 1
				|| check_flag(game, borders, i, j))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	if (unique != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main_flag_validator(t_game *game, char **map)
{
	size_t	*map_borders;

	map_borders = (size_t *)malloc(sizeof(size_t) * game->map_size);
	if (!map_borders)
		catch_error(game, E_NOMEM);
	get_borders(game, map, map_borders);
	if (validate_flags(game, map, map_borders, 0))
	{
		free_single((void *)&map_borders);
		return (EXIT_FAILURE);
	}
	free_single((void *)&map_borders);
	return (EXIT_SUCCESS);
}
