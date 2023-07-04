/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:38:21 by armartir          #+#    #+#             */
/*   Updated: 2023/07/01 10:38:28 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_direction(t_game *game, char pov, double y, double x)
{
	game->player.pos.x = x + 0.5;
	game->player.pos.y = y + 0.5;
	if (pov == 'E')
	{
		game->player.dir.x = 1;
		game->point.x = 0;
		game->point.y = 0.66;
	}
	else if (pov == 'W')
	{
		game->player.dir.x = -1;
		game->point.x = 0;
		game->point.y = -0.66;
	}
	else if (pov == 'S')
	{
		game->player.dir.y = 1;
		game->point.x = -0.66;
	}
	else if (pov == 'N')
		game->player.dir.y = -1;
}

int	player_position(t_game *game)
{
	double	i;
	double	j;
	int		count;

	i = 5;
	count = 0;
	while (game->map[(int)++i])
	{
		j = -1;
		while (game->map[(int)i][(int)++j])
		{
			if (ft_strchr("NSWE", game->map[(int)i][(int)j]))
			{
				if (count++)
					return (EXIT_FAILURE);
				set_direction(game, game->map[(int)i][(int)j], i, j);
				game->map[(int)i][(int)j] = '0';
			}
		}
	}
	if (!count)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	copy_texture(int **address, void *img)
{
	int	arr[3];
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)mlx_get_data_addr(img, &arr[0], &arr[1], &arr[2]);
	*address = (int *)malloc(sizeof(int) * 4096);
	while (i < 4096)
	{
		(*address)[i] = tmp[i];
		i++;
	}
}

void	get_textures(t_mlx *mlx, t_game *game, int **add, char *path)
{
	void	*tmp_img;
	int		arr[2];

	if (check_xpm_file(path))
		catch_error(game, E_WREXT);
	tmp_img = mlx_xpm_file_to_image(mlx->mlx, path, &arr[0], &arr[1]);
	if (!tmp_img || arr[0] != 64 || arr[1] != 64)
	{
		if (tmp_img)
			mlx_destroy_image(mlx->mlx, tmp_img);
		catch_error(game, E_XPM);
	}
	copy_texture(add, tmp_img);
	mlx_destroy_image(mlx->mlx, tmp_img);
}