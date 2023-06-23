#include "cub3D.h"

t_mlx	*init_mlx(t_game *game)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		catch_error(game, E_NOMEM);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		catch_error(game, E_MLXLIB);
	mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, TITLE);
	if (!mlx->win)
		catch_error(game, E_MLXLIB);
	mlx->img_ptr = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT);
	if (!mlx->img_ptr)
		catch_error(game, E_MLXLIB);
    mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->line_len, &mlx->endian);
    if (!mlx->addr)
		catch_error(game, E_MLXLIB);
    return (mlx);
}

void	game_loop(t_mlx *mlx, t_game *game)
{
	int		x;
	int		y;
	char	*addr;
	void	*img;
	mlx_hook(mlx->win, 17, 1L << 17, close_win, &mlx);

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
