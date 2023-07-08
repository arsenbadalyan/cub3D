/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:37:49 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 19:06:40 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	texture_configure(t_mlx *mlx)
{
	t_game	*g;

	g = mlx->game;
	get_textures(mlx, g, &g->map_t.no, g->options->path_to_no);
	get_textures(mlx, g, &g->map_t.so, g->options->path_to_so);
	get_textures(mlx, g, &g->map_t.ea, g->options->path_to_ea);
	get_textures(mlx, g, &g->map_t.we, g->options->path_to_we);
	get_textures(mlx, g, &g->map_t.door, "./sprites/Sprites/door.xpm");
	get_textures(mlx, g, &g->sp.soldier_1, "./sprites/Sprites/w_1.xpm");
	get_textures(mlx, g, &g->sp.soldier_2, "./sprites/Sprites/w_2.xpm");
	get_textures(mlx, g, &g->sp.soldier_3, "./sprites/Sprites/w_3.xpm");
	get_textures(mlx, g, &g->sp.soldier_4, "./sprites/Sprites/w_4.xpm");
	get_textures(mlx, g, &g->sp.soldier_5, "./sprites/Sprites/w_5.xpm");
	get_textures(mlx, g, &g->sp.soldier_6, "./sprites/Sprites/w_6.xpm");
	get_textures(mlx, g, &g->sp.soldier_7, "./sprites/Sprites/w_7.xpm");
}

void	game_loop(t_mlx *mlx, t_game *game)
{
	game_init(game);
	player_position(game);
	mlx->sp_x = get_sp_x(mlx->game->map, '2');
	mlx->sp_y = get_sp_y(mlx->game->map, '2');
	texture_configure(mlx);
	mlx_loop_hook(mlx->mlx, &create_walls, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, &keys, mlx);
	mlx_hook(mlx->win, 6, 1L << 0, &mouse, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, &close_win, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_mlx	*mlx;

	argv++;
	argc--;
	game = init_game();
	parse_controller(game, argv, argc);
	mlx = init_mlx(game);
	game_loop(mlx, game);
	puts("ara");
	system("leaks cub3D");
	return (EXIT_SUCCESS);
}
