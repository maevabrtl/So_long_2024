#include "../../Includes/so_long.h"

int			apply_graphics(game);
void		draw_map(t_so_long *game, t_position pos);
void		put_player(t_so_long *game);
t_graphics	get_and_convert_images(t_so_long *game);
t_graphics	set_to_null(imgs);

int	apply_graphics(game)
{
	t_position	pos;

	pos.y = 0;
	while (pos.y < game->map.height)
	{
		pos.x = 0;
		while (pos.x < game->map.width)
		{
			if (game->map[pos.y][pos.x] == FLOOR
				|| game->map[pos.y][pos.x] == WALL
				|| game->map[pos.y][pos.x] == COLLECT
				|| game->map[pos.y][pos.x] == EXIT)
				draw_map(game, pos);
			if (game->map[pos.y][pos.x] == PLAYER)
			{
				game->player = pos;
				put_player(game);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	draw_map(t_so_long *game, t_position pos)
{
	if (game->map[pos.y][pos.x] == WALL)
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.wall, (pos.x * TILE_SIZE), (pos.y * TILE_SIZE));
	else
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.floor, (pos.x * TILE_SIZE), (pos.y * TILE_SIZE));
	if (game->map[pos.y][pos.x] == COLLECT)
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.collectible, (pos.x * SPRITE_SIZE), (pos.y * SPRITE_SIZE));
	if (game->map[pos.y][pos.x] == EXIT)
		mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.exit, (pos.x * SPRITE_SIZE), (pos.y * SPRITE_SIZE));
}

void	put_player(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.floor, (game->player.x * TILE_SIZE), (game->player.y * TILE_SIZE));
	mlx_put_image_to_window(game->mlx.connection, game->mlx.window, game->imgs.player, (game->player.x * SPRITE_SIZE), (game->player.y * SPRITE_SIZE));
}

t_graphics	get_and_convert_images(t_so_long *game)
{
	int			width;
	int			height;

	game->imgs = set_to_null(imgs);
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx.connection, WALL_XPM, &width, &height);
	if (game->imgs.wall == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, "C2S", game, game->map.map);
	game->imgs.floor = mlx_xpm_file_to_image(game->mlx.connection, FLOOR_XPM, &width, &height);
	if (game->imgs.floor == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, "IC2S", game, game->map.map);
	game->imgs.collect = mlx_xpm_file_to_image(game->mlx.connection, COLLECT_XPM, &width, &height);
	if (game->imgs.collect == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, "IC2S", game, game->map.map);
	game->imgs.exit = mlx_xpm_file_to_image(game->mlx.connection, EXIT_XPM, &width, &height);
	if (game->imgs.exit == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, "IC2S", game, game->map.map);
	game->imgs.player = mlx_xpm_file_to_image(game->mlx.connection, PLAYER_XPM, &width, &height);
	if (game->imgs.player == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, "IC2S", game, game->map.map);
	return (game->imgs);
}

t_graphics	set_to_null(imgs)
{
	imgs.wall = NULL;
	imgs.floor = NULL;
	imgs.collect = NULL;
	imgs.exit = NULL;
	imgs.player = NULL;
	return (imgs);
}
