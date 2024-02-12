#ifndef ERROR_H
# define ERROR_H

/* error codes */
# define NO_PROBLEM 1
# define WRONG_ARGS 2
# define OP_FAIL 3
# define NOT_RECT 4
# define INVALID_ELEM 5
# define TOO_MANY_P 6
# define NO_P 7
# define NO_COLL 8
# define TOO_MANY_E 9
# define NO_E 10
# define NOT_CLOSED 11
# define NOT_WINNABLE 12
# define NOT_BER 13
# define ALLOC_BOUM 14
# define SO_MUCH_DIRT 15
# define VOID_MAP 16

/* error messages */
# define HELP_CALL "\
To launch the game, type \"./so_long <map_path>\" in your command line.\n"
# define OPEN_FAILED "\
Attempt to open the map failed :\nPlease check the path you provided.\n"
# define ALLOC_ERROR "\
Memory allocation failed. You've hacked the Matrice. Congrats.\n"
# define EMPTY_MAP "\
Get_next_line() returned and empty line, something's weird in your map file !\n"
#define DIRTY_TALK "\
Couldn't clean all the data, more variables than format \
specifiers in clean function.\n"
# define MAP_RULES "\
The 10 Commandments for a map to be allowed in So_long :\n"
# define RULE_RECTANGLE "\
The map must be rectangular.\n"
# define RULE_VALID_ELEM "\
The map must contain only 'C's, 'P's, 'E's, '1's and '0's.\n"
# define RULE_PLAYER_1 "\
There must be only one player ('P'). This isn't a multi game yet !\n"
# define RULE_PLAYER_2 "\
But, what's a game without a player ? The map needs a player ('P') !\n"
# define RULE_COLL "\
The map must contain at least one collectible ('C').\n"
# define RULE_EXIT_1 "\
Only one exit ('E') is allowed. No easy way out for you buddy !\n"
# define RULE_EXIT_2 "\
This game needs and exit ('E'), this is not a jail !\n"
# define RULE_CLOSED "\
Walls ('1') have to closed the map for \
it to be valid.\n"
# define RULE_WINNABLE "\
The map must be winnable !\n\
There must be a path for the player \
('P') to collect all the collectibles \
('C') and exit ('E').\n\
Reminder : The player is blocked by \
walls ('1') ! He can move on everything\
 else tho.\n"
# define RULE_NEED_A_MAP "\
This game must be called with a string \
containing <The Path To The Chosen Map> \
as only argument.\n"
# define RULE_BER "\
Last but not least : The Map File must \
end with .ber\n"

#endif
