#include "cub3D.h"

// Function declarations
static char** get_clear_map(char **map);

/*
	Removing options part from map
	to have more clear map
*/
static char** get_clear_map(char** map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < REQUIRED_IDS)
	{
		free(map[i]);
		i++;
	}
	j = i;
	i = 0;
	while(map[i])
	{
		map[i] = map[j + i];
		i++;
	}
	return (map);
}

int call_validator(t_game *game, char **map)
{
	if(validate_options(game, map))
		return (EXIT_FAILURE);
	game->map = get_clear_map(map);
	map = game->map;
	game->map_size = get_2d_array_length((void **)map);
	if (main_flag_validator(game, map))
		return (EXIT_FAILURE);
	// validate file paths
	// start validating map
	return (EXIT_SUCCESS);
}

