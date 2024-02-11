#include "../../Includes/so_long.h"

char	**free_map_copy(char **map, int nb_strs_to_free)
{
	while (nb_strs_to_free >= 0)
	{
		free(map[nb_strs_to_free]);
		map[nb_strs_to_free] = NULL;
		nb_strs_to_free--;
	}
	free(map);
	map = NULL;
	return (map);
}

char	**dup_map(t_map map)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = malloc(sizeof(char *) * map.height);
	if (map_copy == NULL)
		return (NULL);
	y = -1;
	while (++y < map.height)
	{
		x = -1;
		map_copy[y] = malloc(sizeof(char) * map.width);
		if (map_copy[y] == NULL)
			return (free_map_copy(map_copy, y))
		while (++x < map.width)
			map_copy[y][x] = map.map[y][x];
	}
	return (map_copy);
}

int	has_path_to_exit(t_map map)
{
	char		**map_copy;
	t_position	player;

	map_copy = dup_map(map);
	if (map_copy == NULL)
		return (FALSE);
	player.x = 0;
	player.y = 0;
}

/*

si D (done, deja visité) || 1 => mur
	-> ret 0
si E (exit)
	-> mark it as M (?? done ? path found ?)
	-> ret 0
mark as Done
return (recursive de x + 1 ou x - 1 ou y + 1 ou y -1)

*/
