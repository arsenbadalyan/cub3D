/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:36:43 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 15:18:45 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		catch_error(game, E_NOMEM);
	game->options = init_options();
	if (!game->options)
		catch_error(game, E_NOMEM);
	game->map = NULL;
	return (game);
}

t_options	*init_options(void)
{
	t_options	*options;

	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		return (NULL);
	options->path_to_no = NULL;
	options->path_to_so = NULL;
	options->path_to_ea = NULL;
	options->path_to_we = NULL;
	ft_bzero((void *)options->floor_colors, sizeof(int) * 4);
	ft_bzero((void *)options->ceil_colors, sizeof(int) * 4);
	return (options);
}

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
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->line_len, &mlx->endian);
	if (!mlx->addr)
		catch_error(game, E_MLXLIB);
	mlx->game = game;
	mlx->sp_x = 0;
	mlx->sp_y = 0;
	return (mlx);
}

void	init_ray(t_game *game)
{
	game->ray.dir.x = -1;
	game->ray.dir.y = 0;
	game->ray.delta.x = 0;
	game->ray.delta.y = 0;
	game->ray.side.x = 0;
	game->ray.side.y = 0;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.vert_hit = 0;
	game->ray.i = 0;
}

void	game_init(t_game *game)
{
	game->pos_mouse.x = W_WIDTH / 2;
	game->pos_mouse.y = W_HEIGHT / 2;
	game->map_t.no = NULL;
	game->map_t.so = NULL;
	game->map_t.we = NULL;
	game->map_t.ea = NULL;
	game->map_t.door = NULL;
	game->sp.texture = NULL;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
	game->player.dir.x = 0;
	game->player.dir.y = 0;
	game->point.x = 0.66;
	game->point.y = 0;
	game->wall.height = 0;
	game->wall.top = 0;
	game->wall.tex_x = 0;
	game->wall.tex_y = 0;
	game->wall.dist = 0;
	init_ray(game);
}
