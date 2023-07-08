/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:38:00 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 11:06:02 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_minimap(t_mlx *mlx, int color, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < y + 5)
	{
		j = x;
		while (j < x + 5)
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
				color = 0xFFFFFF;
			else if (game->map[i][j] == '1')
				color = 0x6495ED;
			else if (game->map[i][j] == '2')
				color = 0x8CB4FF;
			if (game->map[i][j] == '0' || game->map[i][j] == '1'
				|| game->map[i][j] == '2')
				draw_minimap(mlx, color, j * 5, (i - 5) * 5);
		}
	}
	draw_minimap(mlx, 0xFF0000,
		(int)game->player.pos.x * 5, ((int)game->player.pos.y - 5) * 5);
}
