#include "cub3D.h"

t_game *init_game()
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	if(!game)
		catch_error(game, E_NOMEM);
	game->options = init_options();
	if(!game->options)
		catch_error(game, E_NOMEM);
	game->map = NULL;
	return (game);
}

t_options *init_options()
{
	t_options *options;

	options = (t_options *)malloc(sizeof(t_options));
	if(!options)
		return (NULL);
	options->path_to_no = NULL;
	options->path_to_so = NULL;
	options->path_to_ea = NULL;
	options->path_to_we = NULL;
	ft_bzero((void *)options->floor_colors, sizeof(int) * 3);
	ft_bzero((void *)options->ceil_colors, sizeof(int) * 3);
	return (options);
}