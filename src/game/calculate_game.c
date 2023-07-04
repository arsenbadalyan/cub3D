/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:35:15 by armartir          #+#    #+#             */
/*   Updated: 2023/07/01 16:17:56 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate(t_game *g)
{
	double	x;

	x = g->ray.i * 2.0 / (double)W_WIDTH - 1.0;
	g->ray.dir.x = g->player.dir.x + g->point.x * x;
	g->ray.dir.y = g->player.dir.y + g->point.y * x;
	g->map_t.x = (int)g->player.pos.x;
	g->map_t.y = (int)g->player.pos.y;
	g->ray.delta.x = fabs(1.0 / g->ray.dir.x);
	g->ray.delta.y = fabs(1.0 / g->ray.dir.y);
	g->ray.step_x = 1;
	g->ray.side.x = (g->map_t.x + 1.0 - g->player.pos.x) * g->ray.delta.x;
	g->ray.step_y = 1;
	g->ray.side.y = (g->map_t.y + 1.0 - g->player.pos.y) * g->ray.delta.y;
	if (g->ray.dir.x < 0)
	{
		g->ray.step_x = -1;
		g->ray.side.x = (g->player.pos.x - g->map_t.x) * g->ray.delta.x;
	}
	if (g->ray.dir.y < 0)
	{
		g->ray.step_y = -1;
		g->ray.side.y = (g->player.pos.y - g->map_t.y) * g->ray.delta.y;
	}
}

void	shoot_ray(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (game->ray.side.x < game->ray.side.y)
		{
			game->ray.side.x += game->ray.delta.x;
			game->map_t.x += game->ray.step_x;
			game->ray.vert_hit = 0;
		}
		else
		{
			game->ray.side.y += game->ray.delta.y;
			game->map_t.y += game->ray.step_y;
			game->ray.vert_hit = 1;
		}
		if (game->map[(int)game->map_t.y][(int)game->map_t.x] == '1')
			hit = 1;
	}
}

void	wall(t_game *game)
{
	if (!game->ray.vert_hit)
		game->wall.dist = game->ray.side.x - game->ray.delta.x;
	else
		game->wall.dist = game->ray.side.y - game->ray.delta.y;
	game->wall.height = (int)(W_HEIGHT / game->wall.dist);
	game->wall.top = -game->wall.height / 2 + W_HEIGHT / 2;
}

void	wall_texture(t_game *game)
{
	double	x;

	if (!game->ray.vert_hit)
		x = game->player.pos.y + game->wall.dist * game->ray.dir.y;
	else
		x = game->player.pos.x + game->wall.dist * game->ray.dir.x;
	x -= floor(x);
	game->wall.tex_x = (int)(x * 64.0);
	if ((!game->ray.vert_hit && game->ray.dir.x > 0)
		|| (game->ray.vert_hit && game->ray.dir.y < 0))
		game->wall.tex_x = 64 - game->wall.tex_x - 1;
}

int	find(t_game *game, int x, int y)
{
	int	*tmp;

	if (!game->ray.vert_hit)
	{
		if (game->ray.dir.x >= 0)
			tmp = game->map_t.ea;
		else
			tmp = game->map_t.we;
	}
	else
	{
		if (game->ray.dir.y >= 0)
			tmp = game->map_t.so;
		else
			tmp = game->map_t.no;
	}
	return (tmp[64 * y + x]);
}
