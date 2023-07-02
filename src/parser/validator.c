#include "cub3D.h"

// Function declarations
static char** get_clear_map(t_game* game, char** map, size_t i, size_t j);

/*
	Removing options part from map
	to have more clear map
*/
static char** get_clear_map(t_game* game, char** map, size_t i, size_t j)
{
	size_t	size;

	size = 0;
	i = 0;
	while (map[i] && size < REQUIRED_IDS)
	{
		if (is_full_line(game, map[i]))
			size++;
		free_single((void *)&map[i]);
		i++;
	}
	while(map[i] && !is_full_line(game, map[i]))
	{
		free_single((void *)&map[i]);
		i++;
	}
	j = i;
	i = 0;
	while(map[j + i])
 	{
 		map[i] = map[j + i];
 		i++;
 	}
	map[i] = NULL;
	return (map);
}

int call_validator(t_game *game, char **map)
{
	if(validate_options(game, map, 0, 0))
		return (EXIT_FAILURE);
	game->map = get_clear_map(game, map, 0, 0);
	map = game->map;
	game->map_size = get_2d_array_length((void **)map);
	if (main_flag_validator(game, map))
		return (EXIT_FAILURE);
	// validate file paths
	// start validating map
	return (EXIT_SUCCESS);
}

