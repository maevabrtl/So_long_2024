/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:49:38 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 15:49:39 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_map	*content_is_valid(int fd, t_map *map)
{
	char	*line;
	size_t	index;

	index = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_free_sl(line, fd);
		clean_and_exit(EMPTY_MAP, NULL, NULL, map);
	}
	map->width = ft_strlen(line) - 1;
	while (line[index] == WALL)
		index++;
	if (map->width <= 2 || index != map->width)
		ft_free_sl(line, fd);
	if (map->width <= 2)
		clean_and_exit(INVALID_ELEM, NULL, NULL, map);
	if (index != map->width)
		clean_and_exit(NOT_RECT, NULL, NULL, map);
	check_line(fd, map, line);
	return (map);
}

char	*check_line(int fd, t_map *map, char *line)
{
	size_t	index;

	index = 0;
	map->height = 0;
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		while (is_valid_element(line[index]) == TRUE)
			index++;
		if (index < map->width && is_valid_element(line[index]) == FALSE)
			return (ft_free_sl(line, fd),
				clean_and_exit(INVALID_ELEM, NULL, NULL, map), NULL);
		else if (index != map->width
			|| (index == map->width && line[index] != '\n'))
			return (ft_free_sl(line, fd),
				clean_and_exit(NOT_RECT, NULL, NULL, map), NULL);
	}
	free(line);
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
		&& path[len - 3] == 'b' && path[len - 4] == '.')
		return ;
	clean_and_exit(NOT_BER, NULL, NULL, NULL);
}

size_t	is_closed_and_rectangular(t_map *map)
{
	size_t	x;
	size_t	y;

	if (map->height == map->width)
		clean_and_exit(NOT_RECT, NULL, NULL, map);
	y = -1;
	while (++y < map->height)
		if (map->map[y][map->width - 1] != WALL
			|| map->map[y][0] != WALL)
			clean_and_exit(NOT_CLOSED, NULL, NULL, map);
	y--;
	x = -1;
	while (++x < map->width - 1)
		if (map->map[y][x] != WALL)
			clean_and_exit(NOT_CLOSED, NULL, NULL, map);
	return (TRUE);
}
