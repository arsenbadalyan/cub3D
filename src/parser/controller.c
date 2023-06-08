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

	line = NULL;
	trimmed = NULL;
	map = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		trimmed = ft_strtrim(line, WHITE_SPACE);
		if(!trimmed)
			catch_error(game, E_NOMEM);
		if(ft_strlen(trimmed))
			push_to_double_array(map, line);
		free_single((void *)&trimmed);
		free_single((void *)&line);
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

void	parse_controller(t_game *game, char **argv, int argc)
{
	if(argc != 1)
		catch_error(game, E_WRARG);
	game->map = open_map(game, argv[0]);
	if (!game->map)
		catch_error(game, E_WRCNF);
	if (call_validator(game, game->map))
		catch_error(game, E_WRCNF);
}