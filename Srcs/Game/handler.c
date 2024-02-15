#include "../../Includes/so_long.h"

void		launch_game(t_so_long *game);
int			keypressed_move(int key, t_so_long *game);
static int	update_and_check_case(t_so_long *game, int x, int y);
int			exit_game(char *message, t_so_long *game);
int			print_nb_moves(int nb_moves);

void	launch_game(t_so_long *game)
{
	game->mlx_window = mlx_new_window(game->mlx_connection, game->map->width * 70, game->map->height * 70, "mabertha's so_long");
	if (!game->mlx_window)
		clean_and_exit(LAUNCH_WINDOW_FAIL, game, NULL, NULL);
	game->mlx_clean = 2;
	apply_graphics(game);
	mlx_loop_hook(game->mlx_connection, put_player, game);
	mlx_key_hook(game->mlx_window, keypressed_move, game);
	mlx_hook(game->mlx_window, CLOSING_WINDOW, NO_MASK, exit_game, WINDOW_CLOSED);
	mlx_loop(game->mlx_connection);
}

int	keypressed_move(int key, t_so_long *game)
{
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->floor, (game->player->x * 70), (game->player->y * 70));
	if (key == W_KEY)
		if (update_and_check_case(game, game->player->x, MOVE_UP(game->player->y)) == TRUE)
			game->player->y = MOVE_UP(game->player->y);
	if (key == S_KEY)
		if (update_and_check_case(game, game->player->x, MOVE_DOWN(game->player->y)) == TRUE)
			game->player->y = MOVE_DOWN(game->player->y);
	if (key == A_KEY)
		if (update_and_check_case(game, MOVE_LEFT(game->player->x), game->player->y) == TRUE)
			game->player->x = MOVE_LEFT(game->player->x);
	if (key == D_KEY)
		if (update_and_check_case(game, MOVE_RIGHT(game->player->x), game->player->y) == TRUE)
			game->player->x = MOVE_RIGHT(game->player->x);
	if (key == CLOSE_KEY)
		exit_game(WINDOW_CLOSED, game);
	return (key);
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

int	exit_game(char *message, t_so_long *game)
{
	clean_and_exit(message, game, NULL, NULL);
	return (0);
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
