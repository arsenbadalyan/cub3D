#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	argv++;
	argc--;
	game = init_game();
	parse_controller(game, argv, argc);
	return (EXIT_SUCCESS);
}
