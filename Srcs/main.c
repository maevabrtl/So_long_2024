#include "../Includes/so_long.h"

int			main(int ac, char **av);
void		print_map(t_map map);
t_so_long	*init_struct_game(t_so_long *game, t_map *map);

int	main(int ac, char **av)
{
	t_so_long	*game;
	t_map		*map;

	// ft_putstr_fd("\033[0;33mSTART\n\033[0m", 2);
	if (ac != 2)
		clean_and_exit(WRONG_ARGS, NULL, NULL, NULL);
	map = parse_map(av[1]);
	game = NULL;
	game = init_struct_game(game, map);
	get_and_convert_images(game);
	print_map(*(game->map));
	launch_game(game);
	return (0);
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
	return (game);
}

void	print_map(t_map map)
{
	size_t x;
	size_t y;

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
