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

# define FLOOR_XPM "Ressources/XPM_imgs/floor.xpm"
# define WALL_XPM "Ressources/XPM_imgs/wall.xpm"
# define PLAYER_XPM "Ressources/XPM_imgs/player.xpm"
# define COLLECT_XPM "Ressources/XPM_imgs/collectible.xpm"
# define EXIT_XPM "Ressources/XPM_imgs/exit.xpm"

#endif
