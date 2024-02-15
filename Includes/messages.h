#ifndef ERROR_H
# define ERROR_H

# define WIN "\
\n\
               ,-,\n\
 Congrats !!! ;  ;\n\
           __..--''``---....___   _..._ _     __\n\
       _.-'    _./^\\  `        ``<._     ``.' _ `.\n\
   _.-' _..--.` -   {                       `/  ) ;\n\
  (_..-'    ( C  _   `\\...__                ;  (,'\n\
             `-._,_,*--'    ``--...____..-'\n\n"

/* BASICS */

# define WRONG_ARGS "\
This game must be called with a string \
containing <The Path To The Chosen Map> \
as only argument.\n"

# define OP_FAIL "\
Attempt to open the map failed :\n\
Please check the path you provided.\n"

# define ALLOC_BOUM "\
Memory allocation failed. \
You've hacked the Matrice. Congrats.\n"


/* MLX */

# define DISPLAY_INIT_FAIL "\
MLX failed to init connection with graphical \
window.\n"

# define XPM_CONVERSION_FAIL "\
MLX failed to convert xpm files to images.\n"

# define LAUNCH_WINDOW_FAIL "\
MLX failed to launch graphical window.\n"

# define WINDOW_CLOSED "\
Game window has been closed. So long !\n"


/* MAP */

# define NOT_RECT "\
The map must be rectangular.\n"

# define INVALID_ELEM "\
The map must contain only 'C's, 'P's, \
'E's, '1's and '0's.\n"

# define TOO_MANY_P "\
There must be only one player ('P'). \
This isn't a multi game yet !\n"

# define NO_P "\
But, what's a game without a player ?\
 The map needs a player ('P') !\n"

# define NO_COLL "\
The map must contain at least one \
collectible ('C'). Cats are hungry buddy !\n"

# define TOO_MANY_E "\
Only one exit ('E') is allowed. \
No easy way out for you buddy !\n"

# define NO_E "\
This game needs and exit ('E'), this is \
not a jail !\n"

# define NOT_CLOSED "\
Walls ('1') have to closed the map for \
it to be valid.\n"

# define NOT_WINNABLE "\
The map must be winnable !\n\
There must be a path for the player \
('P') to collect all the collectibles \
('C') and exit ('E').\n\
Reminder : The player is blocked by \
walls ('1') ! He can move on everything\
 else tho.\n"

# define NOT_BER "\
Last but not least : The Map File must \
end with .ber\n"

# define EMPTY_MAP "\
Get_next_line() returned and empty line, \
something's weird in your map file !\n"

# define MAP_OVERSIZE "\
Map is bigger than screen, please put a smaller\
 map you glutton !\n"

#endif
