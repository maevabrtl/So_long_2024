/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:43:11 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 23:30:17 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_map	*init_map_struct(int fd)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_free_sl(NULL, fd),
			clean_and_exit(ALLOC_BOUM, NULL, NULL, NULL), NULL);
	map->map = NULL;
	map->nb_collect = 0;
	map->width = 0;
	map->height = 0;
	map->spawn = malloc(sizeof(t_position));
	map->exit = malloc(sizeof(t_position));
	if (!map->exit || !map->spawn)
		return (ft_free_sl(NULL, fd),
			clean_and_exit(ALLOC_BOUM, NULL, NULL, map), NULL);
	map->spawn->x = -1;
	map->exit->x = -1;
	return (content_is_valid(fd, map));
}

char	**init_map_str(char **map, size_t height)
{
	size_t	i;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (NULL);
	while (i < height)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}

t_so_long	*init_struct_game(t_so_long *game, t_map *map)
{
	game = malloc(sizeof(t_so_long));
	if (game == NULL)
		clean_and_exit(ALLOC_BOUM, NULL, NULL, map);
	game->mlx_connection = NULL;
	game->mlx_window = NULL;
	game->img = NULL;
	game->player = NULL;
	game->map = NULL;
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
		clean_and_exit(DISPLAY_INIT_FAIL, game, NULL, map);
	game->mlx_clean = 1;
	game->player = malloc(sizeof(t_position));
	if (game->player == NULL)
		clean_and_exit(ALLOC_BOUM, game, NULL, map);
	game->map = map;
	game->img = set_to_null(game->img);
	if (game->img == NULL)
		clean_and_exit(ALLOC_BOUM, game, NULL, NULL);
	if (check_size(game->mlx_connection, game->map) == FALSE)
		clean_and_exit(MAP_OVERSIZE, game, NULL, NULL);
	return (game);
}

t_graphics	*set_xpm(t_so_long *game)
{
	t_graphics	*xpm;

	xpm = malloc(sizeof(t_graphics));
	if (xpm == NULL)
		clean_and_exit(ALLOC_BOUM, game, NULL, NULL);
	xpm->wall = ft_strdup(WALL_XPM);
	xpm->floor = ft_strdup(FLOOR_XPM);
	xpm->collect = ft_strdup(COLLECT_XPM);
	xpm->exit = ft_strdup(EXIT_XPM);
	xpm->player = ft_strdup(PLAYER_XPM);
	if (xpm->wall == NULL || xpm->floor == NULL
		|| xpm->collect == NULL || xpm->exit == NULL
		|| !xpm->player)
		clean_and_exit(ALLOC_BOUM, game, xpm, NULL);
	return (xpm);
}

t_graphics	*set_to_null(t_graphics *img)
{
	img = malloc(sizeof(t_graphics));
	if (!img)
		return (NULL);
	img->wall = NULL;
	img->floor = NULL;
	img->collect = NULL;
	img->exit = NULL;
	img->player = NULL;
	return (img);
}
