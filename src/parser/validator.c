#include "cub3D.h"

int call_validator(t_game *game, char **map)
{
	if(validate_options(game, map))
		return (EXIT_FAILURE);
	// validate file paths
	// start validating map
	return (EXIT_SUCCESS);
}

