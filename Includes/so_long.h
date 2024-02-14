#ifndef SO_LONG_H
# define SO_LONG_H

# include "macros.h"
# include "structs.h"
# include "messages.h"
# include <../mlx/mlx.h>
# include "Libft/Includes/libft.h"
# include "Libft/Includes/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

/* In Srcs/Game/clean_and_exit.c */

int			clean_and_exit(char *message, t_so_long *struct_var, char *vars_to_free_list, ...);
int			free_str_var(char **to_free, char alloc_ptr, int index);
void		free_images(t_so_long *game);
int			free_mlx_var(t_mlx to_clean, char display_or_both, int index);
void		free_struct(t_so_long *to_free);

/* In Srcs/Game/graphics.c */

int			apply_graphics(t_so_long *game);
void		draw_map(t_so_long *game, t_position pos);
int			put_player(t_so_long *game);
t_graphics	get_and_convert_images(t_so_long *game);
t_graphics	set_to_null(t_graphics imgs);

/* In Srcs/Game/handler.c */

void		launch_game(t_so_long *game);
int			keypressed_move(int key, t_so_long *game);
// static int	update_and_check_case(t_so_long *game, int x, int y);
int			exit_game(char *message, t_so_long *game);
int			print_nb_moves(int nb_moves);

/* In Srcs/Parsing/is_valid_map.c */

t_map		content_is_valid(int fd, t_map map);
char		*check_line(int fd, t_map *map);
size_t		is_valid_element(char elem);
void		ends_with_ber(char *path);
size_t		is_closed_and_rectangular(t_map map);

/* In Srcs/Parsing/is_winnable_map.c */

size_t		is_winnable(t_map map);
size_t		find_valid_path(char **map, size_t y, size_t x, t_check *checker);
char		**dup_map(t_map map);
char		**free_map_copy(char **map, ssize_t nb_strs_to_free);

/* In Srcs/Parsing/parse_map.c */

t_map		parse_map(char *map_path);
t_map		init_map_struct(void);
t_map		fill_map(int fd, t_map map);
size_t		copy_line(t_map *map, char *line, size_t y, int fd);
size_t		store_and_check_elems_data(t_map *map, char elem, size_t x, size_t y);

/* Srcs/main.c */

int			main(int ac, char **av);
void		print_map(t_map map);

#endif
