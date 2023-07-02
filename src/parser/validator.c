#include "cub3D.h"

// Function declarations
static char** get_clear_map(t_game* game, char** map);

/*
	Removing options part from map
	to have more clear map
*/
static char** get_clear_map(t_game* game, char** map)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = 0;
	while (map[i] && size < REQUIRED_IDS)
	{
		free_single((void *)&map[i]);
		if (!is_empty_line(game, map[i]))
			size++;
		i++;
	}
	map = &map[i];
	// printf("|%lu|%s|\n", i, map[0]);
	return (map);
}

int call_validator(t_game *game, char **map)
{
	if(validate_options(game, map, 0, 0))
		return (EXIT_FAILURE);
	game->map = get_clear_map(game, map);
	map = game->map;
	free_double((void *)&game->map);
	game->map_size = get_2d_array_length((void **)map);
	// if (main_flag_validator(game, map))
	// 	return (EXIT_FAILURE);
	// validate file paths
	// start validating map
	return (EXIT_SUCCESS);
}

