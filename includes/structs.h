/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:33:39 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 15:18:25 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// Game structures
typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_map
{
	int		*no;
	int		*so;
	int		*we;
	int		*ea;
	int		*door;
	int		f;
	int		c;
	int		x;
	int		y;
}	t_map;

typedef struct s_wall
{
	int		height;
	int		top;
	int		tex_x;
	double	tex_y;
	double	dist;
}	t_wall;

typedef struct s_player {
	t_point	pos;
	t_point	dir;
}	t_player;

typedef struct s_colors {
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_ray
{
	t_point	dir;
	t_point	delta;
	t_point	side;
	int		i;
	int		step_x;
	int		step_y;
	int		vert_hit;
}	t_ray;

typedef struct s_options {
	char	*path_to_no;
	char	*path_to_so;
	char	*path_to_we;
	char	*path_to_ea;
	int		floor_colors[4];
	int		ceil_colors[4];
}	t_options;

typedef struct s_sprite {
	double	sp_x;
	double	sp_y;
	double	inv_d;
	double	tr_x;
	double	tr_y;
	int		sp_sc_x;
	int		sp_h;
	int		dr_s_y;
	int		dr_e_y;
	int		sp_w;
	int		dr_s_x;
	int		dr_e_x;
	int		st;
	int		tex_x;
	int		tex_y;
	int		color;
	int		*texture;
	int		*soldier_1;
	int		*soldier_2;
	int		*soldier_3;
	int		*soldier_4;
	int		*soldier_5;
	int		*soldier_6;
	int		*soldier_7;
}	t_sprite;

typedef struct s_game {
	struct s_options	*options;
	char				**map;
	t_player			player;
	t_colors			col;
	t_point				point;
	t_point				pos_mouse;
	t_map				map_t;
	double				x;
	double				y;
	t_wall				wall;
	t_ray				ray;
	t_sprite			sp;
}	t_game;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_game	*game;
	double	zbuffer[W_WIDTH];
	int		sp_x;
	int		sp_y;
}	t_mlx;

#endif
