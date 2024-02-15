/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:58:16 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 15:58:39 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int ac, char **av)
{
	t_so_long	*game;
	t_map		*map;
	t_graphics	*xpm;

	if (ac != 2)
		clean_and_exit(WRONG_ARGS, NULL, NULL, NULL);
	map = parse_map(av[1]);
	game = NULL;
	game = init_struct_game(game, map);
	xpm = NULL;
	get_and_convert_images(game, xpm);
	print_map(*(game->map));
	launch_game(game);
	return (0);
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

t_so_long	*init_struct_game(t_so_long *game, t_map *map)
{
	game = malloc(sizeof(t_so_long));
	if (game == NULL)
		clean_and_exit(ALLOC_BOUM, NULL, NULL, map);
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
		clean_and_exit(DISPLAY_INIT_FAIL, game, NULL, map);
	game->player = malloc(sizeof(t_position));
	if (game->player == NULL)
		clean_and_exit(ALLOC_BOUM, NULL, NULL, map);
	game->map = map;
	game->mlx_clean = 1;
	game->mlx_window = NULL;
	game->img = NULL;
	game->img = set_to_null(game->img);
	if (check_size(game->mlx_connection, game->map) == FALSE)
		clean_and_exit(MAP_OVERSIZE, game, NULL, NULL);
	return (game);
}

void	print_map(t_map map)
{
	size_t	x;
	size_t	y;

	ft_putstr_fd("\n", 1);
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			ft_putchar_fd(map.map[y][x], 1);
			x++;
		}
		ft_putstr_fd("\n", 1);
		y++;
	}
	ft_putstr_fd("\n", 1);
}
