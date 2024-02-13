#include "../Includes/so_long.h"

int		main(int ac, char **av);
void	print_map(t_map map);

int	main(int ac, char **av)
{
	t_so_long	*game;

	ft_putstr_fd(WIN, 1);
	ft_putstr_fd("\033[0;33mSTART\n\033[0m", 2);
	if (ac != 2)
		clean_and_exit(WRONG_ARGS, NULL, NULL);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		clean_and_exit(ALLOC_BOUM, NULL, NULL);
	game->win_or_not = FALSE;
	game->map = parse_map(av[1]);
	print_map(game->map);
	game->mlx_var.connection = mlx_init();
	if (!game->mlx_var.connection)
		clean_and_exit(DISPLAY_INIT_FAIL, "S", game);
	game->graphics = get_and_convert_graphics(game);
	launch_game(game);
	return (0);
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
}
