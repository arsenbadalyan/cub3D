#include "cub3D.h"

int	mouse(int x, int y, t_mlx *mlx)
{
	int 	key;
	t_game	*g;

	(void)y;
	puts("HELLO");
	g = mlx->game;
	if (x < g->pos_mouse.x && x < W_WIDTH / 2)
		key = LEFT_ARROW;
	else if (x > g->pos_mouse.x && x > W_WIDTH / 2)
		key = RIGHT_ARROW;
	g->pos_mouse.x = x;
	if (key == LEFT_ARROW || key == RIGHT_ARROW)
		rotate_player(key, g, SPD_R_M);
	return (0);
}

void	game_loop(t_mlx *mlx, t_game *game)
{
	game_init(game);
	if (player_position(game))
		catch_error(game, E_WRCNF);
	get_textures(mlx, game, &game->map_t.no, game->options->path_to_no);
	get_textures(mlx, game, &game->map_t.so, game->options->path_to_so);
	get_textures(mlx, game, &game->map_t.ea, game->options->path_to_ea);
	get_textures(mlx, game, &game->map_t.we, game->options->path_to_we);
	mlx_loop_hook(mlx->mlx, &create_walls, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, &keys, mlx);
	mlx_hook(mlx->win, 6, 1L << 0, &mouse, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, &close_win, mlx);
	mlx_loop(mlx->mlx);
}

int main(int argc, char **argv)
{
	t_game	*game;
	t_mlx	*mlx;

	argv++;
	argc--;
	game = init_game();
	parse_controller(game, argv, argc);
	mlx = init_mlx(game);
	game_loop(mlx, game);
	return (EXIT_SUCCESS);
}
