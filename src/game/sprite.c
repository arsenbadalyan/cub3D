/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:31:01 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 16:45:59 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_sp_x(char **map, char c)
{
	int	i;
	int	j;

	i = 5;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
				return (j);
		}
	}
	return (0);
}

int	get_sp_y(char **map, char c)
{
	int	i;
	int	j;

	i = 5;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
				return (i);
		}
	}
	return (0);
}

void	animation(t_mlx *mlx)
{
	t_game		*g;
	static int	i;

	g = mlx->game;
	if (i < 20)
		g->sp.texture = g->sp.soldier_1;
	else if (i < 40)
		g->sp.texture = g->sp.soldier_2;
	else if (i < 60)
		g->sp.texture = g->sp.soldier_3;
	else if (i < 80)
		g->sp.texture = g->sp.soldier_4;
	else if (i < 100)
		g->sp.texture = g->sp.soldier_5;
	else if (i < 120)
		g->sp.texture = g->sp.soldier_6;
	else if (i < 140)
	{
		g->sp.texture = g->sp.soldier_7;
		if (i == 139)
			i = 0;
	}
		i++;
}

void	my_sprite_draw(t_mlx *mlx, t_game *g)
{
	int		y;
	int		d;

	g->sp.dr_e_x = g->sp.sp_w / 2 + g->sp.sp_sc_x;
	if (g->sp.dr_e_x >= W_WIDTH)
		g->sp.dr_e_x = W_WIDTH - 1;
	g->sp.st = g->sp.dr_s_x;
	while (g->sp.st < g->sp.dr_e_x)
	{
		g->sp.tex_x = (int)(256 * (g->sp.st - (-g->sp.sp_w
						/ 2 + g->sp.sp_sc_x)) * 64 / g->sp.sp_w) / 256;
		if (g->sp.tr_y > 0 && g->sp.st > 0 && g->sp.st < W_WIDTH
			&& g->sp.tr_y < mlx->zbuffer[g->sp.st])
		y = g->sp.dr_s_y;
		while (y < g->sp.dr_e_y)
		{
			d = (y) * 256 - W_HEIGHT * 128 + g->sp.sp_h * 128;
			g->sp.tex_y = ((d * 64) / g->sp.sp_h) / 256;
			g->sp.color = g->sp.texture[64 * g->sp.tex_y + g->sp.tex_x];
			if (g->sp.color != 0x000000)
				my_mlx_pixel_put(mlx, g->sp.st, y, g->sp.color);
			y++;
		}
		g->sp.st++;
	}
}

void	my_sprite(t_mlx *mlx, int x, int y)
{
	t_game	*g;

	g = mlx->game;
	g->sp.sp_x = x - g->player.pos.x + 0.2;
	g->sp.sp_y = y - g->player.pos.y + 0.2;
	g->sp.inv_d = 1.0 / (g->point.y
			* g->player.dir.x - g->player.dir.y * g->point.x);
	g->sp.tr_x = g->sp.inv_d * (-g->player.dir.y
			* g->sp.sp_x + g->player.dir.x * g->sp.sp_y);
	g->sp.tr_y = g->sp.inv_d * (-g->point.x
			* g->sp.sp_y + g->point.y * g->sp.sp_x);
	g->sp.sp_sc_x = (int)((W_WIDTH / 2) * (1 + g->sp.tr_x / g->sp.tr_y));
	g->sp.sp_h = abs((int)(W_HEIGHT / (g->sp.tr_y)));
	g->sp.dr_s_y = -g->sp.sp_h / 2 + W_HEIGHT / 2;
	if (g->sp.dr_s_y < 0)
		g->sp.dr_s_y = 0;
	g->sp.dr_e_y = g->sp.sp_h / 2 + W_HEIGHT / 2;
	if (g->sp.dr_e_y >= W_HEIGHT)
		g->sp.dr_e_y = W_HEIGHT - 1;
	g->sp.sp_w = abs ((int)(W_HEIGHT / (g->sp.tr_y)));
	g->sp.dr_s_x = -g->sp.sp_w / 2 + g->sp.sp_sc_x;
	if (g->sp.dr_s_x < 0)
		g->sp.dr_s_x = 0;
	my_sprite_draw(mlx, g);
}
