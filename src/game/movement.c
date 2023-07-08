/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:38:13 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 17:13:16 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse(int x, int y, t_mlx *mlx)
{
	int		key;
	t_game	*g;

	(void)y;
	key = 0;
	g = mlx->game;
	if (x < g->pos_mouse.x && x < W_WIDTH / 2)
		key = LEFT_ARROW;
	else if (x > g->pos_mouse.x && x > W_WIDTH / 2)
		key = RIGHT_ARROW;
	g->pos_mouse.x = x;
	if (key == LEFT_ARROW || key == RIGHT_ARROW)
		rotate_player(key, g, SPD_R * 0.15);
	return (0);
}

void	forw_back_move(int key, t_game *g)
{
	t_player	*p;

	p = &g->player;
	if (key == KEY_W)
	{
		if (g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * S)] == '0'
			|| g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * S)] == '2'
			|| g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * S)] == '4')
			p->pos.x += p->dir.x * S;
		if (g->map[(int)(p->pos.y + p->dir.y * S)][(int)(p->pos.x)] == '0'
			|| g->map[(int)(p->pos.y + p->dir.y * S)][(int)(p->pos.x)] == '2'
			|| g->map[(int)(p->pos.y + p->dir.y * S)][(int)(p->pos.x)] == '4')
			p->pos.y += p->dir.y * S;
	}
	else if (key == KEY_S)
	{
		if (g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x * S)] == '0'
			|| g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x * S)] == '2'
			|| g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x * S)] == '4')
			p->pos.x -= p->dir.x * S;
		if (g->map[(int)(p->pos.y - p->dir.y * S)][(int)(p->pos.x)] == '0'
			|| g->map[(int)(p->pos.y - p->dir.y * S)][(int)(p->pos.x)] == '2'
			|| g->map[(int)(p->pos.y - p->dir.y * S)][(int)(p->pos.x)] == '4')
			p->pos.y -= p->dir.y * S;
	}
}

void	rotate_player(int key, t_game *g, double r)
{
	double	dir_x;
	double	point_x;

	dir_x = g->player.dir.x;
	point_x = g->point.x;
	if (key == LEFT_ARROW)
	{
		g->player.dir.x = g->player.dir.x * cos(-r)
			- g->player.dir.y * sin(-r);
		g->player.dir.y = dir_x * sin(-r) + g->player.dir.y * cos(-r);
		g->point.x = g->point.x * cos(-r) - g->point.y * sin(-r);
		g->point.y = point_x * sin(-r) + g->point.y * cos(-r);
	}
	else if (key == RIGHT_ARROW)
	{
		g->player.dir.x = g->player.dir.x * cos(r)
			- g->player.dir.y * sin(r);
		g->player.dir.y = dir_x * sin(r) + g->player.dir.y * cos(r);
		g->point.x = g->point.x * cos(r) - g->point.y * sin(r);
		g->point.y = point_x * sin(r) + g->point.y * cos(r);
	}
}

void	left_right_move(int key, t_game *g)
{
	t_player	*p;

	p = &g->player;
	if (key == KEY_D)
	{
		if (g->map[(int)(p->pos.y)][(int)(p->pos.x + g->point.x * S)] == '0'
			|| g->map[(int)(p->pos.y)][(int)(p->pos.x + g->point.x * S)] == '2'
			|| g->map[(int)(p->pos.y)][(int)(p->pos.x + g->point.x * S)] == '4')
			p->pos.x += g->point.x * S;
		if (g->map[(int)(p->pos.y + g->point.y * S)][(int)(p->pos.x)] == '0'
			|| g->map[(int)(p->pos.y + g->point.y * S)][(int)(p->pos.x)] == '2'
			|| g->map[(int)(p->pos.y + g->point.y * S)][(int)(p->pos.x)] == '4')
			p->pos.y += g->point.y * S;
	}
	else if (key == KEY_A)
	{
		if (g->map[(int)(p->pos.y)][(int)(p->pos.x - g->point.x * S)] == '0'
			|| g->map[(int)(p->pos.y)][(int)(p->pos.x - g->point.x * S)] == '2'
			|| g->map[(int)(p->pos.y)][(int)(p->pos.x - g->point.x * S)] == '4')
			p->pos.x -= g->point.x * S;
		if (g->map[(int)(p->pos.y - g->point.y * S)][(int)(p->pos.x)] == '0'
			|| g->map[(int)(p->pos.y - g->point.y * S)][(int)(p->pos.x)] == '2'
			|| g->map[(int)(p->pos.y - g->point.y * S)][(int)(p->pos.x)] == '4')
			p->pos.y -= g->point.y * S;
	}
}

int	keys(int key, t_mlx *mlx)
{
	t_game	*game;

	game = mlx->game;
	if (key == ESC)
		close_win(mlx);
	else if (key == KEY_F)
		open_the_door(mlx);
	else if (key == KEY_W || key == KEY_S)
		forw_back_move(key, game);
	else if (key == KEY_A || key == KEY_D)
		left_right_move(key, game);
	else if (key == RIGHT_ARROW || key == LEFT_ARROW)
		rotate_player(key, game, SPD_R);
	return (0);
}
