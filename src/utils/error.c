#include "cub3D.h"

void	catch_error(t_game *game, const char *msg)
{
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	free_all_mem(game);
	exit(EXIT_FAILURE);
}
