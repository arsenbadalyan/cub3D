#ifndef UTILS_H
#define UTILS_H

// [ Initialize ]
t_game *init_game();

// [ Mutations ]
size_t get_2d_array_length(void **array);
char **init_2d_array(void);
char **push_to_double_array(char **arr, char *new_line);

// [ Free memory ]
void *free_single(void **addr);
void *free_double(void ***addr);
void free_all_mem(t_game *game);

// [ Error handling ]
void catch_error(t_game *game, const char* msg);

#endif