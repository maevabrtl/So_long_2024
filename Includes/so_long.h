#ifndef SO_LONG_H
# define SO_LONG_H

# include "macros.h"
# include "structs.h"
# include "error.h"
# include "Libft/Includes/libft.h"
# include "Libft/Includes/get_next_line.h"
// # include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>

/* In Parse/parse_map.c */

t_map	parse_map(char *map_path);
t_map	init_map_struct(void);
t_map	fill_map(int fd, t_map map);
size_t	copy_line(t_map *map, char *line, size_t y, int fd);
size_t	store_and_check_elems_data(t_map *map, char elem, size_t x, size_t y);

/* In Parse/is_valid_map.c */

t_map	content_is_valid(int fd, t_map map);
char	*check_line(int fd, t_map *map);
size_t	is_valid_element(char elem);
void	ends_with_ber(char *path);
size_t	is_closed_and_rectangular(t_map map);

/* In Parse/is_winnable.c */

size_t	is_winnable(t_map map);
size_t	find_valid_path(char **map, size_t y, size_t x, t_check *checker);
char	**dup_map(t_map map);
char	**free_map_copy(char **map, ssize_t nb_strs_to_free);
size_t	ft_strlen(const char *s);

void	clean_and_exit(int	error_code, int	nb_to_clean, char *format, ...);
void	get_var_and_clean_it(int nb_to_clean, char *format, va_list to_clean);
int		var_is_a_str(int	index, char *format, va_list to_clean);
int		var_is_an_int_tab(int	index, va_list to_clean);
int		var_is_a_ptr(int	index, va_list to_clean);
int		var_is_a_fd(int	index, va_list to_clean);
void	map_error(int error_code);
void	nb_args_error(int error_code);
void	print_error(int	error_code);

#endif
