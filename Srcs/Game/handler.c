#include "../../Includes/so_long.h"

void		launch_game(t_so_long *game);
int			keypressed_move(int key, t_so_long *game);
static int	update_and_check_case(t_so_long *game, int x, int y);
int			exit_game(char *message);

void	launch_game(t_so_long *game)
{
	game->mlx.window = mlx_new_window(game->mlx.connection, game->map.width * 60, game->map.height * 60, "mabertha's so_long");
	if (!game->mlx.window)
		clean_and_exit(LAUNCH_WINDOW_FAILED, "IC2M1S", game, game->map.map);
	apply_graphics(game);
	mlx_loop_hook(game->mlx.connection, draw_player, game);
	mlx_key_hook(game->mlx.window, keypress_move, game);
	mlx_hook(game->mlx.window, WINDOW_CLOSED, NO_MASK, exit_game, WINDOW_CLOSED);
	mlx_loop(game->mlx.connection);
}

int	keypressed_move(int key, t_so_long *game)
{
	mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.floor, (pos.x * TILE_SIZE), (pos.y * TILE_SIZE));
	if (key == W_KEY)
		if (update_and_check_case(game, game->player.x, game->player.MOVE_UP(y)) == TRUE)
			MOVE_UP(y);
	if (key == S_KEY)
		if (update_and_check_case(game, game->player.x, game->player.MOVE_DOWN(y)) == TRUE)
			MOVE_DOWN(y);
	if (key == A_KEY)
		if (update_and_check_case(game, game->player.MOVE_LEFT(x), game->player.y) == TRUE)
			MOVE_LEFT(y);
	if (key == D_KEY)
		if (update_and_check_case(game, game->player.MOVE_RIGHT(x), game->player.y) == TRUE)
			MOVE_RIGHT(y);
	if (key == CLOSE_KEY)
		exit_game(WINDOW_CLOSED, "IC2M2S", game, game->map.map);
	return (key);
}

static int	update_and_check_case(t_so_long *game, int x, int y)
{
	static int	nb_moves;

	if (game->map.map[y][x] == COLLECT)
	{
		game->map.map[y][x] = FLOOR;
		game->map.nb_collect--;
	}
	if (nb_collect == 0)
	{
		if (game->map.map[y][x] == EXIT)
		{
			print_nb_moves(nb_moves + 1);
			exit_game(WIN, "IC2M2S", game, game->map.map);
		}
	}
	if (game->map.map[y][x] == FLOOR || game->map.map[y][x] == PLAYER)
	{
		nb_moves++;
		print_nb_moves(nb_moves);
		return (TRUE);
	}
	return (FALSE);
}

int	exit_game(char *message)
{
	game->win_or_not = TRUE;
	clean_and_exit(message, "IC2M2S", game, game->map.map);
	return (0);
}
