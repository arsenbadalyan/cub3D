/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:37:49 by armartir          #+#    #+#             */
/*   Updated: 2023/07/01 17:37:58 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define uDiv 1
#define vDiv 1
#define vMove 0.0

void	my_sprite(t_mlx *mlx)
{
	t_game	*g;

	g = mlx->game;

	// printf("%f\n%f\n",g->player.pos.x,g->player.pos.y);

	double spriteX = 1 - g->player.pos.x;
	double spriteY = 7 - g->player.pos.y;

	// double invDet = 1.0 / (g->point.y * g->player.dir.x - g->player.dir.y * g->point.x);
	double invDet = 1.0 / (g->point.y * g->player.dir.x - g->player.dir.y * g->point.x);
    
    // double transformX = invDet * (g->player.dir.x * spriteX - g->player.dir.y * spriteY);
    double transformX = invDet * (-g->player.dir.y * spriteX + g->player.dir.x * spriteY);
	double transformY = invDet * (-g->point.x * spriteY + g->point.y * spriteX) - 1;

	// double	invDet = 1.0 / (g->point.y * g->player.dir.y - g->player.dir.x * g->point.x);

	// double	transformX = invDet * (g->player.dir.y * spriteX - g->player.dir.x * spriteY);
	// double	transformY = invDet * (-g->point.x * spriteX + g->point.y * spriteY);

    int vMoveScreen = (int)(vMove / transformY);

    int spriteScreenX = (int)((W_WIDTH / 2) * (1 + transformX / transformY));
    
	int spriteHeight = abs((int)(W_HEIGHT / (transformY)));
	// int spriteHeight = abs((int)(W_HEIGHT / (transformY))) / vDiv;

    int drawStartY = -spriteHeight / 2 + W_HEIGHT / 2;
    // int drawStartY = -spriteHeight / 2 + W_HEIGHT / 2 + vMoveScreen;
    if(drawStartY < 0) drawStartY = 0;
    int drawEndY = spriteHeight / 2 + W_HEIGHT / 2;
    // int drawEndY = spriteHeight / 2 + W_HEIGHT / 2 + vMoveScreen;
    if(drawEndY >= W_HEIGHT) drawEndY = W_HEIGHT - 1;


    int spriteWidth = abs((int) (W_HEIGHT / (transformY)));
    // int spriteWidth = abs((int) (W_HEIGHT / (transformY))) / uDiv;

	// printf ("W = %d\nH = %d\n", spriteWidth, spriteHeight);

    int drawStartX = -spriteWidth / 2 + spriteScreenX;
    if(drawStartX < 0) drawStartX = 0;
    int drawEndX = spriteWidth / 2 + spriteScreenX;
    if(drawEndX >= W_WIDTH) drawEndX = W_WIDTH - 1;

	for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    {
      int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
      if(transformY > 0 && stripe > 0 && stripe < W_WIDTH )
      for(int y = drawStartY; y < drawEndY; y++)
      {
        int d = (y) * 256 - W_HEIGHT * 128 + spriteHeight * 128;
        // int d = (y-vMoveScreen) * 256 - W_HEIGHT * 128 + spriteHeight * 128;
        int texY = ((d * 64) / spriteHeight) / 256;
			double	scale;
			int		color;
			int		i;

			scale = 64.0 / spriteHeight;
			i = 0;
			// while (i < g->wall.height)
			// {
				// color = find(g, (int)g->wall.tex_x, (int)g->wall.tex_y);
				// puts("HELLO");
				color = g->sp.texture[64 * texY + texX];
				if (color != 0x000000)
					my_mlx_pixel_put(mlx, stripe, y, color);
				// texY += scale;
				i++;
	  }
    }
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
	get_textures(mlx, game, &game->sp.texture, "./sprites/Sprites/barrel.xpm");
	mlx_loop_hook(mlx->mlx, &create_walls, mlx);

	my_sprite(mlx);
	
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
	return (EXIT_SUCCESS);
}












//	int i = 0;
// 	int j = 0;
// 	// puts("ALO");
// 	while (g->map[i])
// 	{
// 		j = 0;	
// 		while (g->map[i][j])
// 		{
// 			// write (1, &g->map[i][j], 1);
// 			if (g->map[i][j] == '2')
// 				printf ("i = %d j = %d\n", i,j);
// 			j++;
// 		}
// 		// write(1, "\n",1 );
// 		i++;
// 	}
