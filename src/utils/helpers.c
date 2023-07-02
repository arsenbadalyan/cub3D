#include "cub3D.h"

int is_full_line(t_game* game, char* line)
{
	size_t	i;

	i = 0;
	if(!line || !line[0])
		return (EXIT_SUCCESS);
	while(line[i])
	{
		if(!ft_strchr(WHITE_SPACE, line[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}