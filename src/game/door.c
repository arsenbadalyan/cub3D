/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:17:55 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 16:38:13 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	open_the_door(t_mlx *mlx)
{
	t_game		*g;
	t_player	*p;

	g = mlx->game;
	p = &g->player;
	if (g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x)] == '3')
		g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x)] = '4';
	else if (g->map[(int)(p->pos.y + p->dir.y)][(int)(p->pos.x)] == '3')
		g->map[(int)(p->pos.y + p->dir.y)][(int)(p->pos.x)] = '4';
	else if (g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x)] == '3')
		g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x)] = '4';
	else if (g->map[(int)(p->pos.y - p->dir.y)][(int)(p->pos.x)] == '3')
		g->map[(int)(p->pos.y - p->dir.y)][(int)(p->pos.x)] = '4';
	else if (g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x)] == '4')
		g->map[(int)p->pos.y][(int)(p->pos.x + p->dir.x)] = '3';
	else if (g->map[(int)(p->pos.y + p->dir.y)][(int)(p->pos.x)] == '4')
		g->map[(int)(p->pos.y + p->dir.y)][(int)(p->pos.x)] = '3';
	else if (g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x)] == '4')
		g->map[(int)p->pos.y][(int)(p->pos.x - p->dir.x)] = '3';
	else if (g->map[(int)(p->pos.y - p->dir.y)][(int)(p->pos.x)] == '4')
		g->map[(int)(p->pos.y - p->dir.y)][(int)(p->pos.x)] = '3';
}
