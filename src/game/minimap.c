#include "cub3D.h"

void	draw_minimap(t_mlx *mlx, int color, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < y + 6)
	{
		j = x;
		while (j < x + 6)
		{
			my_mlx_pixel_put(mlx, j, i, color);
			j++;
		}
		i++;
	}
}

void	minimap(t_mlx *mlx)
{
	t_game	*game;
	int		i;
	int		j;
	int		color;

	game = mlx->game;
	i = 5;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0')
				color = 0x000000;
			else if (game->map[i][j] == '1')
				color = 0x0000FF;
			if (game->map[i][j] == '0' || game->map[i][j] == '1')
				draw_minimap(mlx, color, j * 6, (i - 5) * 6);
		}
	}
	draw_minimap(mlx, 0x00FF00,
		(int)game->player.pos.x * 6, ((int)game->player.pos.y - 5) * 6);
}
