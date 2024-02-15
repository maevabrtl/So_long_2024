/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:41:11 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 20:38:45 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	launch_game(t_so_long *game)
{
	game->mlx_window = mlx_new_window(game->mlx_connection,
			game->map->width * 70, game->map->height * 70, "so_long");
	if (!game->mlx_window)
		clean_and_exit(LAUNCH_WINDOW_FAIL, game, NULL, NULL);
	game->mlx_clean = 2;
	apply_graphics(game);
	mlx_loop_hook(game->mlx_connection, put_player, game);
	mlx_key_hook(game->mlx_window, keypressed_move, game);
	mlx_hook(game->mlx_window, CLOSING_WINDOW, NO_MASK,
		exit_on_window_closing, game);
	mlx_loop(game->mlx_connection);
}

static int	update_and_check_case(t_so_long *game, int x, int y)
{
	static int	nb_moves;

	if (game->map->map[y][x] == COLLECT)
	{
		game->map->map[y][x] = FLOOR;
		game->map->nb_collect--;
	}
	if (game->map->nb_collect == 0)
	{
		if (game->map->map[y][x] == EXIT)
		{
			print_nb_moves(nb_moves + 1);
			exit_game(WIN, game);
		}
	}
	if (game->map->map[y][x] == FLOOR || game->map->map[y][x] == PLAYER)
	{
		nb_moves = print_nb_moves(nb_moves + 1);
		return (TRUE);
	}
	return (FALSE);
}

int	keypressed_move(int key, t_so_long *game)
{
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->img->floor, (game->player->x * 70), (game->player->y * 70));
	if (key == W_KEY)
		if (update_and_check_case(game, game->player->x,
				game->player->y - 1) == TRUE)
			game->player->y = game->player->y - 1;
	if (key == S_KEY)
		if (update_and_check_case(game, game->player->x,
				game->player->y + 1) == TRUE)
			game->player->y = game->player->y + 1;
	if (key == A_KEY)
		if (update_and_check_case(game, game->player->x - 1,
				game->player->y) == TRUE)
			game->player->x = game->player->x - 1;
	if (key == D_KEY)
		if (update_and_check_case(game, game->player->x + 1,
				game->player->y) == TRUE)
			game->player->x = game->player->x + 1;
	if (key == CLOSE_KEY)
		exit_game(WINDOW_CLOSED, game);
	return (key);
}

int	print_nb_moves(int nb_moves)
{
	if (nb_moves == 1)
		ft_putstr_fd("1st move !\n", 1);
	else if (nb_moves == 2)
		ft_putstr_fd("2nd move !\n", 1);
	else if (nb_moves == 3)
		ft_putstr_fd("3rd move !\n", 1);
	else
	{
		ft_putnbr_fd(nb_moves, 1);
		ft_putstr_fd("th move !\n", 1);
	}
	return (nb_moves);
}
