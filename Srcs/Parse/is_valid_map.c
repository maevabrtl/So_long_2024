#include "../../Includes/so_long.h"

void	ends_with_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] == 'r' && path[len - 2] == 'e'
		&& path[len - 3] == 'b' && path[len - 4 ] == '.')
		return ;
	exit_error(0, 0, NULL);
}

int		is_valid_element(char elem)
{
	if (elem == WALL || elem == FLOOR
		|| elem == PLAYER || elem == EXIT
		|| elem == COLLECT)
		return (TRUE);
	return (FALSE);
}

char	*check_line(int fd, t_map *map)
{
	int		index;
	char	*line;

	index = 0;
	line = get_next_line(fd)
	if (!line || ft_strlen(line) != map->width)
		exit_error(2, fd, line, map);
	while (is_valid_element(line[index]) == TRUE)
		index++;
	if (index != map.width)
		exit_error(2, fd, line, map);
	return (line);
}

t_map	content_is_valid(int fd, t_map map)
{
	char	*line;
	int		index;

	index = 0;
	line = get_next_line(fd);
	map.width = ft_strlen(line);
	if (!line || map.width <= 3)
		exit_error(1, fd, &map);
	map.height = 0;
	while (line[index] == WALL)
		index++;
	if (index != map.width - 1)
		exit_error(2, fd, &map, line);
	while (line)
	{
		map.height++;
		free(line);
		line = check_line(fd, &map);
	}
	free(line);
	return (map)
}

int	store_and_check_elems_data(t_map *map, char elem, int x, int y)
{
	if (elem == PLAYER && map->spawn.x == -1)
	{
		map->player.x = x;
		map->player.y = y
	}
	else if (elem == PLAYER)
		return (FALSE);
	if (elem == EXIT && map->exit.x == -1)
	{
		map->exit.x = x;
		map->exit.y = y;
	}
	else if (elem == EXIT)
		return (FALSE);
	if (elem == COLLECT)
		map->nb_collect++;
	return (TRUE);
}

int	copy_line(t_map *map, char *line, int y)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (store_and_check_elems_data(map, line[x], x, y) == FALSE)
			return (FALSE);
		map->map[y][x] = line[x];
		x++;
	}
	map->map[y][x] = '\0';
	if (map->nb_collect == 0)
		return (FALSE);
	return (TRUE);
}

t_map	init_map_infos(int fd, t_map map)
{
	char	*line;
	int		y;

	line = get_next_line(fd);
	map.map = malloc(sizeof(char *) * map.height + 1)
	if (map.map == NULL || line == NULL)
		exit_error(2, fd, &map, line)
	y = -1;
	while (++y < map.heigth)
	{
		map.map[y] = malloc(sizeof(char) * map.width);
		if (map.map[y] == NULL || copy_line(&map, line, y) == FALSE)
			exit_error(2, fd, &map, line);
		line = get_next_line(fd);
		if (line == NULL || map == NULL)
			exit_error(2, fd, &map, line);
	}
	return (map);
}

int	is_closed_and_rectangular(t_map map)
{
	int	x;
	int	y;

	if (map.height == map.width - 1)
		return (FALSE);
	y = -1
	while (++y < map.height)
		if (map.map[y][map.width - 2] != WALL
			|| map.map[y][0] != WALL)
			return (FALSE);
	y--;
	x = -1;
	while (++x < map.width - 1)
		if (map.map[y][x] != WALL)
			return (FALSE);
	return (TRUE);
}

t_map	init_map(int fd)
{
	t_map	map;

	map = malloc(sizeof(t_map) * 1);
	if (map == NULL)
		return (NULL);
	map.map = NULL;
	map.spawn.x = -1;
	map.spawn.next = NULL;
	map.exit.x = -1;
	map.exit.next = NULL;
	map.nb_collect = 0;
	return (map);
}

t_map	parse_map(char *map_path)
{
	int		fd;
	t_map	map;

	if (!map_path || !*map_path)
		exit_error(0, 0, NULL);
	ends_with_ber(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error(0, 0, NULL);
	map = init_map(fd);
	if (map == NULL)
		exit_error(0, fd, NULL);
	map = content_is_valid(fd, map);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error(1, 0, &map);
	map = fill_map(fd, map);
	close(fd);
	if (is_closed_and_rectangular(map) == FALSE
		|| has_path_to_exit(map) == FALSE)
		exit_error(1, 0, &map);
	return (map);
}
