#include "cub3D.h"

static int is_correct_ext(t_game *game, char *map_name)
{
	char **ext;
	size_t size;
	int status;

	status = EXIT_SUCCESS;
	ext = ft_split(map_name, '.');
	if(!ext)
		catch_error(game, E_NOMEM);
	size = get_2d_array_length((void **)ext);
	if(ft_strcmp(ext[size - 1], EXTENTION))
		status = EXIT_FAILURE;
	return (status);
}

static char** fill_map(t_game *game, int fd)
{
	char*	line;
	char*	trimmed;
	char**	map;
	int i = 0;

	line = NULL;
	trimmed = NULL;
	map = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map = push_to_double_array(map, line);
	}
	return (map);
}

static char** open_map(t_game *game, char *map_name)
{
	char** map;
	int fd;

	if(is_correct_ext(game, map_name))
		catch_error(game, E_WREXT);
	fd = open(map_name, O_RDONLY);
	if(fd == -1)
		catch_error(game, E_WRPTH);
	map = fill_map(game, fd);
	close(fd);
	return (map);
}

void	trim_options(t_game *game, char **map)
{
	char*	trimmed;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while(map[i] && size < REQUIRED_IDS)
	{
		if(!is_full_line(game, map[i]) && ++i)
			continue;
		trimmed = ft_strtrim(map[i], WHITE_SPACE);
		if(!trimmed)
			catch_error(game, E_NOMEM);
		free_single((void *)&map[i]);
		map[i] = trimmed;
		size++;
		i++;
	}
}

void	parse_controller(t_game *game, char **argv, int argc)
{
	if(argc != 1)
		catch_error(game, E_WRARG);
	game->map = open_map(game, argv[0]);
	if (!game->map)
		catch_error(game, E_WRCNF);
	trim_options(game, game->map);
	if (call_validator(game, game->map))
		catch_error(game, E_WRCNF);
}