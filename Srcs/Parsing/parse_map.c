#include "../../Includes/so_long.h"

t_map	parse_map(char *map_path);
t_map	init_map_struct(void);
t_map	fill_map(int fd, t_map map);
size_t	copy_line(t_map *map, char *line, size_t y, int fd);
size_t	store_and_check_elems_data(t_map *map, char elem, size_t x, size_t y);

t_map	parse_map(char *map_path)
{
	int		fd;
	t_map	map;

	if (!map_path || !*map_path)
		clean_and_exit(WRONG_ARGS, NULL, NULL);
	ends_with_ber(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		clean_and_exit(OP_FAIL, NULL, NULL);
	map = init_map_struct();
	map = content_is_valid(fd, map);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		clean_and_exit(OP_FAIL, NULL, NULL);
	map = fill_map(fd, map);
	close(fd);
	is_closed_and_rectangular(map);
	if (is_winnable(map) == FALSE)
		clean_and_exit(NOT_WINNABLE, "C2", NULL, map.map);
	return (map);
}

t_map	init_map_struct(void)
{
	t_map	map;

	map.map = NULL;
	map.spawn.x = -1;
	map.exit.x = -1;
	map.nb_collect = 0;
	return (map);
}

t_map	fill_map(int fd, t_map map)
{
	char	*line;
	size_t	y;

	line = get_next_line(fd);
	map.map = malloc(sizeof(char *) * (map.height + 1));
	if (map.map == NULL || line == NULL)
		clean_and_exit(ALLOC_BOUM, "C1C2F", NULL, &line, map.map, fd);
	y = -1;
	while (++y < map.height)
	{
		map.map[y] = malloc(sizeof(char) * map.width + 1);
		if (map.map[y] == NULL)
			clean_and_exit(ALLOC_BOUM, "C2FC1", NULL, map.map, fd, &line);
		copy_line(&map, line, y, fd);
		free(line);
		line = get_next_line(fd);
		if (line == NULL && y < map.height - 1)
			clean_and_exit(ALLOC_BOUM, "C2F", NULL, map.map, fd);
	}
	map.map[y] = NULL;
	if (map.nb_collect == 0)
		clean_and_exit(NO_COLL, "C1C2F", NULL, &line, map.map, fd);
	return (free(line), map);
}

size_t	copy_line(t_map *map, char *line, size_t y, int fd)
{
	size_t	x;
	size_t	checker;

	x = 0;
	while (x < map->width)
	{
		checker = store_and_check_elems_data(map, line[x], x, y);
		if (checker == 2)
			clean_and_exit(TOO_MANY_P, "C2C1F", NULL, (*map).map, &line, fd);
		if (checker == 3)
			clean_and_exit(TOO_MANY_E, "C2C1F", NULL, (*map).map, &line, fd);
		map->map[y][x] = line[x];
		x++;
	}
	map->map[y][x] = '\0';
	return (TRUE);
}

size_t	store_and_check_elems_data(t_map *map, char elem, size_t x, size_t y)
{
	if (elem == PLAYER && map->spawn.x == -1)
	{
		map->spawn.x = x;
		map->spawn.y = y;
	}
	else if (elem == PLAYER)
		return (2);
	else if (elem == EXIT && map->exit.x == -1)
	{
		map->exit.x = x;
		map->exit.y = y;
	}
	else if (elem == EXIT)
		return (3);
	else if (elem == COLLECT)
		map->nb_collect++;
	return (TRUE);
}
