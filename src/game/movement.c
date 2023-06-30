#include "cub3D.h"

void	forw_back_move(int key, t_game *g)
{
	if (key == KEY_W)
	{
		if (g->map[(int)g->player.pos.y]
			[(int)(g->player.pos.x + g->player.dir.x * SPD_P)] == '0')
			g->player.pos.x += g->player.dir.x * SPD_P;
		if (g->map[(int)(g->player.pos.y + g->player.dir.y * SPD_P)]
			[(int)(g->player.pos.x)] == '0')
			g->player.pos.y += g->player.dir.y * SPD_P;
	}
	else if (key == KEY_S)
	{
		if (g->map[(int)g->player.pos.y]
			[(int)(g->player.pos.x - g->player.dir.x * SPD_P)] == '0')
			g->player.pos.x -= g->player.dir.x * SPD_P;
		if (g->map[(int)(g->player.pos.y - g->player.dir.y * SPD_P)]
			[(int)(g->player.pos.x)] == '0')
			g->player.pos.y -= g->player.dir.y * SPD_P;
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
	if (key == KEY_D)
	{
		if (g->map[(int)(g->player.pos.y)]
			[(int)(g->player.pos.x + g->point.x * SPD_P)] == '0')
			g->player.pos.x += g->point.x * SPD_P;
		if (g->map[(int)(g->player.pos.y + g->point.y * SPD_P)]
			[(int)(g->player.pos.x)] == '0')
			g->player.pos.y += g->point.y * SPD_P;
	}
	else if (key == KEY_A)
	{
		if (g->map[(int)(g->player.pos.y)]
			[(int)(g->player.pos.x - g->point.x * SPD_P)] == '0')
			g->player.pos.x -= g->point.x * SPD_P;
		if (g->map[(int)(g->player.pos.y - g->point.y * SPD_P)]
			[(int)(g->player.pos.x)] == '0')
			g->player.pos.y -= g->point.y * SPD_P;
	}
}

int	keys(int key, t_mlx *mlx)
{
	t_game	*game;

	game = mlx->game;
	if (key == ESC)
		close_win(mlx);
	else if (key == KEY_W || key == KEY_S)
		forw_back_move(key, game);
	else if(key == KEY_A || key == KEY_D)
		left_right_move(key, game);
	else if (key == RIGHT_ARROW || key == LEFT_ARROW)
		rotate_player(key, game, SPD_R);
	return (0);
}
