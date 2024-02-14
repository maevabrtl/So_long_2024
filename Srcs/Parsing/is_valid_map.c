#include "../../Includes/so_long.h"

t_map	content_is_valid(int fd, t_map map);
char	*check_line(int fd, t_map *map);
size_t	is_valid_element(char elem);
void	ends_with_ber(char *path);
size_t	is_closed_and_rectangular(t_map map);

t_map	content_is_valid(int fd, t_map map)
{
	char	*line;
	size_t	index;

	index = 0;
	line = get_next_line(fd);
	if (!line)
		clean_and_exit(EMPTY_MAP, NULL, "C1C2F", &line, map.map, fd);
	map.width = ft_strlen(line) - 1;
	if (map.width <= 2)
		clean_and_exit(INVALID_ELEM, NULL, "C1C2F", &line, map.map, fd);
	map.height = 0;
	while (line[index] == WALL)
		index++;
	if (index != map.width)
		clean_and_exit(NOT_RECT, NULL, "C1C2F", &line, map.map, fd);
	while (line)
	{
		map.height++;
		free(line);
		line = check_line(fd, &map);
	}
	return (free(line), map);
}

char	*check_line(int fd, t_map *map)
{
	size_t	index;
	char	*line;

	index = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (is_valid_element(line[index]) == TRUE)
		index++;
	if (index < map->width && is_valid_element(line[index]) == FALSE)
		clean_and_exit(INVALID_ELEM, NULL, "C1C2F", &line, map->map, fd);
	else if (index != map->width || (index == map->width && line[index] != '\n'))
		clean_and_exit(NOT_RECT, NULL, "C1C2F", &line, map->map, fd);
	return (line);
}

size_t	is_valid_element(char elem)
{
	if (elem == WALL || elem == FLOOR
		|| elem == PLAYER || elem == EXIT
		|| elem == COLLECT)
		return (TRUE);
	return (FALSE);
}

void	ends_with_ber(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] == 'r' && path[len - 2] == 'e'
		&& path[len - 3] == 'b' && path[len - 4 ] == '.')
		return ;
	clean_and_exit(NOT_BER, NULL, NULL);
}

size_t	is_closed_and_rectangular(t_map map)
{
	size_t	x;
	size_t	y;

	if (map.height == map.width)
		clean_and_exit(NOT_RECT, NULL, "C2", map.map);
	y = -1;
	while (++y < map.height)
		if (map.map[y][map.width - 1] != WALL
			|| map.map[y][0] != WALL)
			clean_and_exit(NOT_CLOSED, NULL, "C2", map.map);
	y--;
	x = -1;
	while (++x < map.width - 1)
		if (map.map[y][x] != WALL)
			clean_and_exit(NOT_CLOSED, NULL, "C2", map.map);
	return (TRUE);
}
