/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:34:11 by armartir          #+#    #+#             */
/*   Updated: 2023/07/01 10:34:32 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

// [ Initialize ]
t_game		*init_game(void);
t_options	*init_options(void);
void		game_init(t_game *game);
void		init_ray(t_game *game);

// [ Mutations ]
size_t		get_2d_array_length(void **array);
char		**init_2d_array(void);
char		**push_to_double_array(char **arr, char *new_line);

// [ Free memory ]
void		*free_single(void **addr);
void		*free_double(void ***addr);
void		free_all_mem(t_game *game);

// [ Error handling ]
void		catch_error(t_game *game, const char *msg);
int			check_xpm_file(const char *line);

// [ Useful functions ]
int is_correct_ext(t_game* game, char* path, char* check);

#endif