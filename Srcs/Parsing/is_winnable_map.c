/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_winnable_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:50:36 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 23:31:01 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

size_t	is_winnable(t_map map)
{
	char		**map_copy;
	t_position	player;
	t_check		checker;

	map_copy = dup_map(map);
	if (map_copy == NULL)
		return (FALSE);
	player.x = map.spawn->x;
	player.y = map.spawn->y;
	checker.nb_collect = map.nb_collect;
	checker.found_exit = FALSE;
	if (find_valid_path(map_copy, player.y, player.x, &checker) == FALSE)
	{
		free_map_copy(map_copy, map.height);
		return (FALSE);
	}
	free_map_copy(map_copy, map.height);
	return (TRUE);
}

size_t	find_valid_path(char **map, size_t y, size_t x, t_check *checker)
{
	if (checker->nb_collect == 0 && checker->found_exit == TRUE)
		return (TRUE);
	if (map[y][x] == WALL)
		return (FALSE);
	if (map[y][x] == CHECKED)
		return (FALSE);
	if (map[y][x] == COLLECT)
		checker->nb_collect--;
	if (map[y][x] == EXIT)
		checker->found_exit = TRUE;
	map[y][x] = CHECKED;
	if (find_valid_path(map, y, x + 1, checker) == TRUE)
		return (TRUE);
	if (find_valid_path(map, y - 1, x, checker) == TRUE)
		return (TRUE);
	if (find_valid_path(map, y, x - 1, checker) == TRUE)
		return (TRUE);
	if (find_valid_path(map, y + 1, x, checker) == TRUE)
		return (TRUE);
	return (FALSE);
}

char	**dup_map(t_map map)
{
	char	**map_copy;
	size_t	x;
	size_t	y;

	map_copy = malloc(sizeof(char *) * map.height);
	if (map_copy == NULL)
		return (NULL);
	y = -1;
	while (++y < map.height)
	{
		x = -1;
		map_copy[y] = malloc(sizeof(char) * map.width);
		if (map_copy[y] == NULL)
			return (free_map_copy(map_copy, y));
		while (++x < map.width)
			map_copy[y][x] = map.map[y][x];
	}
	return (map_copy);
}

char	**free_map_copy(char **map, ssize_t nb_strs_to_free)
{
	while (--nb_strs_to_free >= 0)
	{
		free(map[nb_strs_to_free]);
		map[nb_strs_to_free] = NULL;
	}
	free(map);
	map = NULL;
	return (map);
}
