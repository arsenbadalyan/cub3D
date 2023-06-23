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
# define W_WIDTH 600
# define W_HEIGHT 600
# define TITLE "Cub3D"

// Error messages
# define E_NOMEM "We have memory issue. Please free space in your memory and come back." 
# define E_WRARG "Please give only 1 argument(map path)."
# define E_WREXT "File extention is wrong. Please give file with .cub extention."
# define E_WRPTH "File you want to run is invalid."
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
typedef struct s_game {
	struct s_options	*options;
	char				**map;
}	t_game;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_options {
	char* path_to_no;
	char* path_to_so;
	char* path_to_we;
	char* path_to_ea;
	int floor_colors[4];
	int ceil_colors[4];
} t_options;

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
int	close_win(t_mlx *p);
int	create_trgb(int t, int r, int g, int b);
#endif