#include "cub3D.h"

t_game *init_game()
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	if(!game)
		catch_error(game, E_NOMEM);
	game->map = NULL;
	return (game);
}