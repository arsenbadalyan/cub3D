#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 

// Constants
# define WHITE_SPACE	" \t\r\n\f\v"
# define EXTENTION		"cub"

// Error messages
# define E_NOMEM "We have memory issue. Please free space in your memory and come back." 
# define E_WRARG "Please give only 1 argument(map path)."
# define E_WREXT "File extention is wrong. Please give file with .cub extention."
# define E_WRPTH "File you want to run is invalid."
# define E_WRCNF "Wrong map configuration. Please fill map in correct way."

// Game structures
typedef struct s_game {
	char **map;
} t_game;

// Custom libs
# include "libft.h"
# include "get_next_line.h"
# include "utils.h"

// Parser part
void	parse_controller(t_game *game, char **argv, int argc);
int		call_validator(t_game *game, char **map);
#endif