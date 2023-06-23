#include "cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(t_mlx *p)
{
	// mlx_clear_window(p->mlx, p->win);
	// mlx_destroy_image(p->mlx, p->img_ptr);
	// mlx_destroy_window(p->mlx, p->win);
	exit (0);
	return (0);
}