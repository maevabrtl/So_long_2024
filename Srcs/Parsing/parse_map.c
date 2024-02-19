/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:50:58 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/16 01:15:54 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_map	*parse_map(char *map_path)
{
	int		fd;
	t_map	*map;

	if (!map_path || !*map_path)
		clean_and_exit(WRONG_ARGS, NULL, NULL, NULL);
	ends_with_ber(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		clean_and_exit(OP_FAIL, NULL, NULL, NULL);
	map = init_map_struct(fd);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		clean_and_exit(OP_FAIL, NULL, NULL, map);
	map = fill_map(fd, map);
	if (map->spawn->x == -1)
		clean_and_exit(NO_P, NULL, NULL, map);
	if (map->exit->x == -1)
		clean_and_exit(NO_E, NULL, NULL, map);
	is_closed_and_rectangular(map);
	if (is_winnable(*map) == FALSE)
		clean_and_exit(NOT_WINNABLE, NULL, NULL, map);
	return (map);
}

t_map	*fill_map(int fd, t_map *map)
{
	char	*line;
	size_t	y;

	line = get_next_line(fd);
	map->map = init_map_str(map->map, map->height);
	if (map->map == NULL || line == NULL)
		return (ft_free_sl(line, fd),
			clean_and_exit(ALLOC_BOUM, NULL, NULL, map), NULL);
	y = -1;
	while (++y < map->height)
	{
		map->map[y] = malloc(sizeof(char) * map->width + 1);
		line = copy_line(map, line, y, fd);
		if (line == NULL && y < map->height - 1)
			return (ft_free_sl(line, fd),
				clean_and_exit(ALLOC_BOUM, NULL, NULL, map), NULL);
	}
	map->map[y] = NULL;
	if (map->nb_collect == 0)
		return (ft_free_sl(line, fd),
			clean_and_exit(NO_COLL, NULL, NULL, map), NULL);
	close(fd);
	return (map);
}

char	*copy_line(t_map *map, char *line, size_t y, int fd)
{
	size_t	x;
	size_t	checker;

	if (map->map[y] != NULL)
	{
		x = 0;
		while (x < map->width)
		{
			checker = store_and_check_elems_data(map, line[x], x, y);
			if (checker == 2)
				return (ft_free_sl(line, fd),
					clean_and_exit(TOO_MANY_P, NULL, NULL, map), NULL);
			if (checker == 3)
				return (ft_free_sl(line, fd),
					clean_and_exit(TOO_MANY_E, NULL, NULL, map), NULL);
			map->map[y][x] = line[x];
			x++;
		}
		map->map[y][x] = '\0';
		ft_free_sl(line, 0);
		return (get_next_line(fd));
	}
	else
		return (ft_free_sl(line, fd), NULL);
}

size_t	store_and_check_elems_data(t_map *map, char elem, size_t x, size_t y)
{
	if (elem == PLAYER && map->spawn->x == -1)
	{
		map->spawn->x = x;
		map->spawn->y = y;
	}
	else if (elem == PLAYER)
		return (2);
	else if (elem == EXIT && map->exit->x == -1)
	{
		map->exit->x = x;
		map->exit->y = y;
	}
	else if (elem == EXIT)
		return (3);
	else if (elem == COLLECT)
		map->nb_collect++;
	return (TRUE);
}

int	check_size(void	*connection, t_map *map)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	mlx_get_screen_size(connection, (int *)(&x), (int *)(&y));
	if ((map->height * 70) > y || (map->width * 70) > x)
		return (FALSE);
	return (TRUE);
}
