#include "../../Includes/so_long.h"

int			apply_graphics(t_so_long *game);
void		draw_map(t_so_long *game, t_position pos);
int			put_player(t_so_long *game);
t_graphics	get_and_convert_images(t_so_long *game);
t_graphics	set_to_null(t_graphics img);

int	apply_graphics(t_so_long *game)
{
	t_position	pos;

	pos.y = 0;
	while ((size_t)pos.y < game->map.height)
	{
		pos.x = 0;
		while ((size_t)pos.x < game->map.width)
		{
			if (game->map.map[pos.y][pos.x] == FLOOR
				|| game->map.map[pos.y][pos.x] == WALL
				|| game->map.map[pos.y][pos.x] == COLLECT
				|| game->map.map[pos.y][pos.x] == EXIT)
				draw_map(game, pos);
			if (game->map.map[pos.y][pos.x] == PLAYER)
			{
				game->player = pos;
				put_player(game);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void	draw_map(t_so_long *game, t_position pos)
{
	if (game->map.map[pos.y][pos.x] == WALL)
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->img.wall, (pos.x * TILE_SIZE), (pos.y * TILE_SIZE));
	else
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->img.floor, (pos.x * TILE_SIZE), (pos.y * TILE_SIZE));
	if (game->map.map[pos.y][pos.x] == COLLECT)
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->img.collect, (pos.x * SPRITE_SIZE), (pos.y * SPRITE_SIZE));
	if (game->map.map[pos.y][pos.x] == EXIT)
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->img.exit, (pos.x * SPRITE_SIZE), (pos.y * SPRITE_SIZE));
}

int	put_player(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->img.floor, (game->player.x * TILE_SIZE), (game->player.y * TILE_SIZE));
	mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->img.player, (game->player.x * SPRITE_SIZE), (game->player.y * SPRITE_SIZE));
	return (0);
}

t_graphics	get_and_convert_images(t_so_long *game)
{
	int			width;
	int			height;

	game->img = set_to_null(game->img);
	game->img.wall = mlx_xpm_file_to_image(game->mlx.connection, WALL_XPM, &width, &height);
	if (game->img.wall == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, "C2S", game->map.map);
	game->img.floor = mlx_xpm_file_to_image(game->mlx.connection, FLOOR_XPM, &width, &height);
	if (game->img.floor == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, "C2S", game->map.map);
	game->img.collect = mlx_xpm_file_to_image(game->mlx.connection, COLLECT_XPM, &width, &height);
	if (game->img.collect == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, "C2S", game->map.map);
	game->img.exit = mlx_xpm_file_to_image(game->mlx.connection, EXIT_XPM, &width, &height);
	if (game->img.exit == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, "C2S", game->map.map);
	game->img.player = mlx_xpm_file_to_image(game->mlx.connection, PLAYER_XPM, &width, &height);
	if (game->img.player == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, "C2S", game->map.map);
	return (game->img);
}

t_graphics	set_to_null(t_graphics img)
{
	img.wall = NULL;
	img.floor = NULL;
	img.collect = NULL;
	img.exit = NULL;
	img.player = NULL;
	return (img);
}
