#ifndef MACROS_H
# define MACROS_H

# define TRUE 1
# define FALSE 0

# define CLOSING_WINDOW 17
# define NO_MASK 0

# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define CLOSE_KEY 65307

# define FLOOR '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECT 'C'
# define EXIT 'E'
# define CHECKED 'X'

# define MOVE_RIGHT(x) ((x) + 1)
# define MOVE_LEFT(x) ((x) - 1)
# define MOVE_UP(y) ((y) - 1)
# define MOVE_DOWN(y) ((y) + 1)

# define TILE_SIZE 60
# define SPRITE_SIZE 32

# define FLOOR_XPM "../Ressources/XPM_imgs/F_bricks_path_60.xpm"
# define WALL_XPM "../Ressources/XPM_imgs/W_bush_texture_60.xpm"
# define PLAYER_XPM "../Ressources/XPM_imgs/P_Cat_32.xpm"
# define COLLECT_XPM "../Ressources/XPM_imgs/C_Pig_32.xpm"
# define EXIT_XPM "../Ressources/XPM_imgs/E_bed_32.xpm"

#endif
