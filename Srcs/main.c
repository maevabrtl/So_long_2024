#include "../Includes/so_long.h"

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

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		clean_and_exit(WRONG_ARGS, 0, NULL);
	dprintf(2, "\033[0;33mSTART\n\033[0m");
	map = parse_map(av[1]);
	print_map(map);
	clean_and_exit(NO_PROBLEM, 1, "%C2", map.map);
	return (0);
}
