/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:33:09 by armartir          #+#    #+#             */
/*   Updated: 2023/07/08 19:41:52 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <math.h>

// Keys

# define S 0.6
# define SPD_R 0.2
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

// Constants
# define WHITE_SPACE	" \t\r\n\f\v"
# define EXTENTION		"cub"
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define TITLE "Cub3D"

// Error messages
# define E_NOMEM "We have memory issue. Please free space \
	in your memory and come back."
# define E_WRARG "Please give only 1 argument(map path)."
# define E_WREXT "File extention is wrong. Please give file \
	with .cub extention."
# define E_WRPTH "File you want to run is invalid."
# define E_XPM   ".xpm to file convert error."
# define E_WRCNF "Wrong map configuration. Please fill map in correct way."
# define E_WRXPM "XPM file path is invalid. Please check and run again."
# define E_MLXLIB "MiniLibX error"

// Options identifiers
# define REQUIRED_IDS 6
# define SO_ID "SO"
# define NO_ID "NO"
# define WE_ID "WE"
# define EA_ID "EA"
# define FL_ID "F"
# define CL_ID "C"

// Game flags
# define WALL_FLAG '1'
# define SPACE_FLAG '0'
# define DOOR_FLAG '3'
# define SPRITE_FLAG '2'
# define VALID_FLAGS "1203 \n"
# define UNIQUE_FLAGS "NSEW"

// Custom libs
# include "libft.h"
# include "get_next_line.h"
# include "utils.h"
# include "structs.h"
// Parser part
void	parse_controller(t_game *game, char **argv, int argc);

// Validators
int		call_validator(t_game *game, char **map);
int		validate_options(t_game *game, char **map, int i, int size);
int		main_flag_validator(t_game *game, char **map);
int		is_full_line(char *line);

// MiniLibX
int		close_win(t_mlx *p);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
t_mlx	*init_mlx(t_game *game);

// Calculation
void	set_direction(t_game *game, char pov, double y, double x);
void	player_position(t_game *game);
void	calculate(t_game *game);
void	shoot_ray(t_game *game);

// Minimap
void	minimap(t_mlx *mlx);
void	draw_minimap(t_mlx *mlx, int color, int x, int y);

// Drawing
void	draw_line(t_mlx *mlx, t_game *game);
void	draw_game(t_mlx *mlx);
int		create_walls(t_mlx *mlx);
void	ceiling_floor(t_mlx *mlx, int color, int start);

// Textures
void	wall(t_game *game);
void	wall_texture(t_game *game);
void	copy_texture(int **address, void *img);
int		find(t_game *game, int x, int y);
void	get_textures(t_mlx *mlx, t_game *game, int **add, char *path);

// Movements
int		keys(int key, t_mlx *mlx);
void	left_right_move(int key, t_game *g);
void	rotate_player(int key, t_game *g, double r);
void	forw_back_move(int key, t_game *g);
int		mouse(int x, int y, t_mlx *mlx);

// Sprite
void	my_sprite(t_mlx *mlx, int x, int y);
void	my_sprite_draw(t_mlx *mlx, t_game *g);
void	animation(t_mlx *mlx);
int		get_sp_x(char **map, char c);
int		get_sp_y(char **map, char c);

// Door
void	open_the_door(t_mlx *mlx);

#endif