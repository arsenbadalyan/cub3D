#include "cub3D.h"

/*
    Function prototypes (declarations)
*/
static int cmp_opt(t_game* game, t_options* options, char *id, char *needle);
static int cmp_addn_opt(t_game* game, t_options* options, char *id, char *needle);
static int is_rgb(char *rgb, int *addr, size_t i, size_t j);

/*
    Checking NO, SO, WE, EA options
*/
static int cmp_opt(t_game* game, t_options* options, char *id, char *needle)
{
	char* dup_needle;

	dup_needle = ft_strdup(needle);
	if(!dup_needle)
		catch_error(game, E_NOMEM);
	if (!options->path_to_so && !ft_strcmp(SO_ID, id))
		options->path_to_so = dup_needle;
	else if (!options->path_to_no && !ft_strcmp(NO_ID, id))
		options->path_to_no = dup_needle;
	else if (!options->path_to_we && !ft_strcmp(WE_ID, id))
		options->path_to_we = dup_needle;
	else if (!options->path_to_ea && !ft_strcmp(EA_ID, id))
		options->path_to_ea = dup_needle;
	else
	{
		free_single((void *)&dup_needle);	
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
    This part is rgb colors validator
    rgb must be from 0 to 255
    if other value validation fails
*/
static int is_rgb(char* rgb, int* addr, size_t i, size_t j)
{
	size_t	len;
	int		nbr;

	if(!rgb)
		return (EXIT_FAILURE);
    while(rgb[i + 1] && rgb[i] == '0')
        i++;
	len = ft_strlen(rgb + i);
	if(len < 1 || len > 3)
		return (EXIT_FAILURE);
	j = i;
	while(rgb[i])
	{
		if(!ft_isdigit(rgb[i]))
			return (EXIT_FAILURE);
        i++;
	}
	nbr = ft_atoi(rgb + j);
	if(nbr > 255)
		return (EXIT_FAILURE);
	*addr = nbr;
	return (EXIT_SUCCESS);
}

static int cmp_addn_opt(t_game* game, t_options* options, char *id, char *needle)
{
	size_t	i;
	int*	option_ptr;
	char**	rgb;

	i = 1;
	if (!options->floor_colors[0] && !ft_strcmp(FL_ID, id))
		option_ptr = options->floor_colors;
	else if (!options->ceil_colors[0] && !ft_strcmp(CL_ID, id))
		option_ptr = options->ceil_colors;
	else
		return (EXIT_FAILURE);
	rgb = ft_split(needle, ',');
    if (!rgb)
        catch_error(game, E_NOMEM);
	if (rgb[3] != NULL && !free_double((void *)&rgb))
		return (EXIT_FAILURE);
	while(i < 4)
	{
		if(is_rgb(rgb[i - 1], &option_ptr[i], 0, 0) && !free_double((void *)&rgb))
			return (EXIT_FAILURE);
        i++;
	}
	option_ptr[0] = 1;
	return (EXIT_SUCCESS);
}

/*
    Main function that controls options validation
*/
int validate_options(t_game *game, char **map, int i, int size)
{
	char**	cur_line;
	int		finded;

	cur_line = NULL;
	while (map[i] && size < REQUIRED_IDS)
	{
		if(!is_full_line(game, map[i]) && ++i)
			continue ;
		cur_line = ft_split(map[i], ' ');
		if (!cur_line)
			catch_error(game, E_NOMEM);
		if ((!cur_line[0] || !cur_line[1] || cur_line[2] != NULL)
			&& !free_double((void *)&cur_line))
			return (EXIT_FAILURE);
		if (cmp_opt(game, game->options, cur_line[0], cur_line[1])
            && cmp_addn_opt(game, game->options, cur_line[0], cur_line[1])
			&& !free_double((void *)&cur_line))
            return (EXIT_FAILURE);
		free_double((void *)&cur_line);
		i++;
		size++;
	}
	return (EXIT_SUCCESS);
}
