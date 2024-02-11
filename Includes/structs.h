#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_game
{
	void		*connection;
	void		*window;
}					t_game;

typedef struct		s_position
{
	int			x;
	int			y;
	t_position	*next;
}					t_position;

typedef struct		s_graphics
{
	void		*wall;
	void		*floor;
	void		*collectibles;
	void		*player;
	void		*exit;
}					t_graphics;

typedef struct		s_map
{
	int			width;
	int			height;
	int			nb_collect;
	t_position	spawn;
	t_position	exit;
	char		**map;
}					t_map;

typedef struct		s_so_long
{
	t_map		map;
	t_game		game;
	t_graphics	img;
	t_position	player;
}					t_so_long;


#endif
