
#include "cub3D.h"

void *free_single(void **addr)
{
	if (*addr)
	{
		free(*addr);
		*addr = 0;
	}
	return (0);
}

void *free_double(void ***addr)
{
	int i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_single((void *)&(*addr)[i]);
			i++;
		}
		free_single((void *)&(*addr));
	}
	return (0);
}

void free_all_mem(t_game *game)
{
	free_double((void *)&game->map);
	free_single((void *)&game->options);
	free_single((void *)&game);
}