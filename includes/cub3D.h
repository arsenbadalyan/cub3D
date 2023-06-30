#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <math.h>

// Keys

// Linux
# define SPD_P 0.6
# define SPD_R 0.2
# define SPD_R_M 0.03
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

// # define ESC 53
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define LEFT 123
// # define RIGHT 124

// Constants
# define WHITE_SPACE	" \t\r\n\f\v"
# define EXTENTION		"cub"
# define W_WIDTH 1280
# define W_HEIGHT 720
# define TITLE "Cub3D"

// Error messages
# define E_NOMEM "We have memory issue. Please free space in your memory and come back." 
# define E_WRARG "Please give only 1 argument(map path)."
# define E_WREXT "File extention is wrong. Please give file with .cub extention."
# define E_WRPTH "File you want to run is invalid."
# define E_XPM   ".xpm to file convert error."
# define E_WRCNF "Wrong map configuration. Please fill map in correct way."
# define E_MLXLIB "MiniLibX error"

// Options identifiers
# define REQUIRED_IDS 6
# define SO_ID "SO"
# define NO_ID "NO"
# define WE_ID "WE"
# define EA_ID "EA"
# define FL_ID "F"
# define CL_ID "C"

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
	// int		*an1;
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
	int g;
	int b;
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
	char* path_to_no;
	char* path_to_so;
	char* path_to_we;
	char* path_to_ea;
	int floor_colors[4];
	int ceil_colors[4];
}	t_options;

typedef struct s_game {
	struct s_options	*options;
	char				**map;
	t_player			player;
	t_colors			col;
	t_point				point;
	t_point				wind;
	t_point				pos_mouse;
	t_map				map_t;
	double				x;
	double				y;
	t_wall				wall;
	t_ray				ray;
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
}	t_mlx;

// Custom libs
# include "libft.h"
# include "get_next_line.h"
# include "utils.h"

// Parser part
void	parse_controller(t_game *game, char **argv, int argc);

// Validators
int		call_validator(t_game *game, char **map);
int		validate_options(t_game *game, char **map);

// [ MiniLibX]
int			close_win(t_mlx *p);
int			create_trgb(int t, int r, int g, int b);
t_mlx		*init_mlx(t_game *game);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// Game
void	set_direction(t_game *game, char pov, double y, double x);
int		player_position(t_game *game);
void	copy_texture(int **address, void *img);
void	get_textures(t_mlx *mlx, t_game *game, int **add, char *path);
void	minimap(t_mlx *mlx);
void	draw_minimap(t_mlx *mlx, int color, int x, int y);
void	draw_line(t_mlx *mlx, t_game *game);
void	draw_game(t_mlx *mlx);
int		create_walls(t_mlx *mlx);
void	ceiling_floor(t_mlx *mlx, int color, int start);
void	calculate(t_game *game);
void	shoot_ray(t_game *game);
void	wall(t_game *game);
void	wall_texture(t_game *game);
int		find(t_game *game, int x, int y);
int		keys(int key, t_mlx *mlx);
void	left_right_move(int key, t_game *g);
void	rotate_player(int key, t_game *g, double r);
void	forw_back_move(int key, t_game *g);

#endif