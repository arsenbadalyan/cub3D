#include "cub3D.h"

int call_validator(t_game *game, char **map)
{
	int		i;
	char**	current_line;

	i = 0;
	current_line = NULL;
	while(map[i])
	{
		if(i >= REQUIRED_IDS)
			break;
		current_line = ft_split(map[i], ' ');
		if()
	}
	return (EXIT_SUCCESS);
}

int validate_options(t_game *game, char **map)
{

}

int compare_options(t_options *options, char *needle)
{
	int status;

	status = EXIT_FAILURE;
	if (!ft_strcmp(SO_ID) && !(--status))
		options->path_to_so = needle;
	else if (!ft_strcmp(NO_ID) && !(--status))
		options->path_to_no = needle;
	else if (!ft_strcmp(WE_ID) && !(--status))
		options->path_to_we = needle;
	else if (!ft_strcmp(EA_ID) && !(--status))
		options->path_to_ea = needle;
	return (status);
}
