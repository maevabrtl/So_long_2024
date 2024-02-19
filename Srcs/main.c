/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:58:16 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/16 00:59:45 by mabertha         ###   ########lyon.fr   */
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
	launch_game(game);
	return (0);
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
