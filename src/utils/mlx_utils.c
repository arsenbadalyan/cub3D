#include "cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(t_mlx *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_destroy_image(p->mlx, p->img_ptr);
	mlx_destroy_window(p->mlx, p->win);
	free_all_mem(p->game);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >=0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp/8));
		*(unsigned int *)dst = color;
	}
}

int	check_xpm_file(const char *line)
{
	int	i;
	int	fd;

	i = 0;
	if (!line)
		return (EXIT_FAILURE);
	while (line[i])
		i++;
	if (i < 5 || line[i - 1] != 'm' || line[i - 2] != 'p' || line[i - 3] != 'x'
		|| line[i - 4] != '.')
		return (EXIT_FAILURE);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
