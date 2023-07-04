#include "cub3D.h"

// Function declarations
static char	**get_clear_map(char **map, size_t i, size_t j);
static int	validate_xpm(t_game *game);

/*
	Is valid file paths
*/
static int	validate_xpm(t_game *game)
{
	char	*arr[4];
	size_t	size;
	size_t	i;
	int		fd;

	i = 0;
	size = 4;
	arr[0] = game->options->path_to_ea;
	arr[1] = game->options->path_to_we;
	arr[2] = game->options->path_to_no;
	arr[3] = game->options->path_to_so;
	while (i < size)
	{
		if (is_correct_ext(game, arr[i], "xpm"))
			return (EXIT_FAILURE);
		fd = open(arr[i], O_RDONLY);
		if (fd == -1)
			return (EXIT_FAILURE);
		close(fd);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
	Removing options part from map
	to have more clear map
*/
static char	**get_clear_map(char **map, size_t i, size_t j)
{
	size_t	size;

	size = 0;
	i = 0;
	while (map[i] && size < REQUIRED_IDS)
	{
		if (is_full_line(map[i]))
			size++;
		free_single((void *)&map[i]);
		i++;
	}
	while (map[i] && !is_full_line(map[i]))
	{
		free_single((void *)&map[i]);
		i++;
	}
	j = i;
	i = 0;
	while (map[j + i])
	{
		map[i] = map[j + i];
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	call_validator(t_game *game, char **map)
{
	if (validate_options(game, map, 0, 0))
		return (EXIT_FAILURE);
	game->map = get_clear_map(map, 0, 0);
	map = game->map;
	game->map_size = get_2d_array_length((void **)map);
	if (validate_xpm(game))
		return (EXIT_FAILURE + 1);
	if (main_flag_validator(game, map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
