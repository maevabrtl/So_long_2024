/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:22 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 23:12:53 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "macros.h"
# include "structs.h"
# include "messages.h"
# include "Libft/Includes/libft.h"
# include "Libft/Includes/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

/* In Srcs/Exit_clean/clean_and_exit.c */

int			exit_game(char *message, t_so_long *game);
int			exit_on_window_closing(t_so_long *game);
int			clean_and_exit(char *message, t_so_long *game,
				t_graphics *img, t_map *map);
void		free_sl_struct(t_so_long *to_free);
void		free_graphic_struct(t_graphics *img);

/* In Srcs/Exit_clean/free_tools_sl.c */

void		free_images(void *connection, t_graphics *img);
void		free_mlx_var(void *connection, void *window, int display_or_both);
void		free_map_struct(t_map *map);
void		free_str_var(char **to_free, int nb_to_free);
void		ft_free_sl(char *str, int fd);

/* In Srcs/Game/graphics.c */

int			apply_graphics(t_so_long *game);
void		draw_map(t_so_long *game, t_position pos);
int			put_player(t_so_long *game);
t_graphics	*get_and_convert_images(t_so_long *game, t_graphics *xp);

/* In Srcs/Game/handler.c */

void		launch_game(t_so_long *game);
int			keypressed_move(int key, t_so_long *game);
int			print_nb_moves(int nb_moves);

/* In Srcs/Game/init_tools.c */

t_map		*init_map_struct(int fd);
char		**init_map_str(char **map, size_t height);
t_so_long	*init_struct_game(t_so_long *game, t_map *map);
t_graphics	*set_xpm(t_so_long *game);
t_graphics	*set_to_null(t_graphics *img);

/* In Srcs/Parsing/is_valid_map.c */

t_map		*content_is_valid(int fd, t_map *map);
char		*check_line(int fd, t_map *map, char *line);
size_t		is_valid_element(char elem);
void		ends_with_ber(char *path);
size_t		is_closed_and_rectangular(t_map *map);

/* In Srcs/Parsing/is_winnable_map.c */

size_t		is_winnable(t_map map);
size_t		find_valid_path(char **map, size_t y, size_t x, t_check *checker);
char		**dup_map(t_map map);
char		**free_map_copy(char **map, ssize_t nb_strs_to_free);

/* In Srcs/Parsing/parse_map.c */

t_map		*parse_map(char *map_path);
t_map		*fill_map(int fd, t_map *map);
char		*copy_line(t_map *map, char *line, size_t y, int fd);
size_t		store_and_check_elems_data(t_map *map, char elem,
				size_t x, size_t y);
int			check_size(void	*connection, t_map *map);

/* Srcs/main.c */

int			main(int ac, char **av);
void		print_map(t_map map);

#endif
