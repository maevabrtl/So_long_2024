#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

typedef struct		s_game
{
	void				*connection;
	void				*window;
}					t_game;

typedef struct		s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct		s_check
{
	size_t				nb_collect;
	size_t				found_exit;
}					t_check;

typedef struct		s_graphics
{
	void				*wall;
	void				*floor;
	void				*collectibles;
	void				*player;
	void				*exit;
}					t_graphics;

typedef struct		s_map
{
	size_t				width;
	size_t				height;
	size_t				nb_collect;
	t_position			spawn;
	t_position			exit;
	char				**map;
}					t_map;

typedef struct		s_so_long
{
	t_map				map;
	t_game				game;
	t_graphics			img;
	t_position			player;
}					t_so_long;

#endif
