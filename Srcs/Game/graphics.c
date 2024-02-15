#include "../../Includes/so_long.h"

int			apply_graphics(t_so_long *game);
void		draw_map(t_so_long *game, t_position pos);
int			put_player(t_so_long *game);
t_graphics	*get_and_convert_images(t_so_long *game);
t_graphics	*set_to_null(t_graphics *img);

int	apply_graphics(t_so_long *game)
{
	t_position	*pos;

	pos = malloc(sizeof(t_position));
	if (!pos)
		clean_and_exit(ALLOC_BOUM, game, NULL, NULL);
	pos->y = 0;
	while ((size_t)pos->y < game->map->height)
	{
		pos->x = 0;
		while ((size_t)pos->x < game->map->width)
		{
			if (game->map->map[pos->y][pos->x] == PLAYER)
			{
				game->player->x = pos->x;
				game->player->y = pos->y;
				put_player(game);
			}
			else
				draw_map(game, *pos);
			pos->x++;
		}
		pos->y++;
	}
	free(pos);
	return (0);
}

void	draw_map(t_so_long *game, t_position pos)
{
	if (game->map->map[pos.y][pos.x] == WALL)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->wall, (pos.x * 70), (pos.y * 70));
	else
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->floor, (pos.x * 70), (pos.y * 70));
	if (game->map->map[pos.y][pos.x] == COLLECT)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->collect, (pos.x * 70), (pos.y * 70));
	if (game->map->map[pos.y][pos.x] == EXIT)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->exit, (pos.x * 70), (pos.y * 70));
}

int	put_player(t_so_long *game)
{
	// mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->floor, (game->player->x * TILE_SIZE), (game->player->y * TILE_SIZE));
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img->player, (game->player->x * 70), (game->player->y * 70));
	return (0);
}

t_graphics	*set_xpm(void)
{
	t_graphics *xpm;
	xpm = malloc(sizeof(t_graphics));
	if (xpm == NULL)
		return (NULL);
	xpm->wall = ft_strdup(WALL_XPM);
	xpm->floor = ft_strdup(FLOOR_XPM);
	xpm->collect = ft_strdup(COLLECT_XPM);
	xpm->exit = ft_strdup(EXIT_XPM);
	xpm->player = ft_strdup(PLAYER_XPM);
	if (xpm->wall == NULL || xpm->floor == NULL
		|| xpm->collect == NULL || xpm->exit == NULL
		|| !xpm->player)
		return (NULL);
	return (xpm);
}

t_graphics	*get_and_convert_images(t_so_long *game)
{
	int			width;
	int			height;
	t_graphics	*xpm;

	game->img = set_to_null(game->img);
	xpm = set_xpm();
	if (!game->img || !xpm)
		clean_and_exit(ALLOC_BOUM, game, xpm, NULL);
	game->img->wall = mlx_xpm_file_to_image(game->mlx_connection, xpm->wall, &width, &height);
	if (game->img->wall == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->floor = mlx_xpm_file_to_image(game->mlx_connection, xpm->floor, &width, &height);
	if (game->img->floor == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->exit = mlx_xpm_file_to_image(game->mlx_connection, xpm->exit, &width, &height);
	if (game->img->exit == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->player = mlx_xpm_file_to_image(game->mlx_connection, xpm->player, &width, &height);
	if (game->img->player == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	dprintf(2, "yolo1\n");
	game->img->collect = mlx_xpm_file_to_image(game->mlx_connection, xpm->collect, &width, &height);
	if (game->img->collect == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	dprintf(2, "yolo2\n");
	free_graphic_struct(xpm);
	return (game->img);
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
