#include "cub3D.h"

void		draw_line(t_mlx *mlx, t_game *game)
{
	double	scale;
	int		color;
	int		i;

	scale = 64.0 / (double)game->wall.height;
	game->wall.tex_y = 0;
	i = 0;
	while (i < game->wall.height)
	{
		color = find(game, (int)game->wall.tex_x, (int)game->wall.tex_y);
		my_mlx_pixel_put(mlx, game->ray.i, game->wall.top + i, color);
		game->wall.tex_y += scale;
		i++;
	}
}

void	draw_game(t_mlx *mlx)
{
	t_game	*game;

	game = mlx->game;
	game->ray.i = 0;
	ceiling_floor(mlx, create_trgb(1, game->options->ceil_colors[1],
		game->options->ceil_colors[2], game->options->ceil_colors[3]), 0);
	ceiling_floor(mlx, create_trgb(1, game->options->floor_colors[1],
		game->options->floor_colors[2], game->options->floor_colors[3]), W_HEIGHT / 2);
	while (game->ray.i < W_WIDTH)
	{
		calculate(game);
		shoot_ray(game);
		wall(game);
		wall_texture(game);
		draw_line(mlx, game);
		game->ray.i++;
	}
	minimap(mlx);
}

void	ceiling_floor(t_mlx *mlx, int color, int start)
{
	int	i;
	int	j;

	i = 0;
	while (i < (W_HEIGHT / 2))
	{
		j = 0;
		while (j < W_WIDTH)
		{
			my_mlx_pixel_put(mlx, j, start + i, color);
			j++;
		}
		i++;
	}
}

int	create_walls(t_mlx *mlx)
{
	draw_game(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr, 0, 0);
	return (0);
}
