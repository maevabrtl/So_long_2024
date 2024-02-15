/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:41:04 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 22:45:39 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

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
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->wall, (pos.x * 70), (pos.y * 70));
	else
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->floor, (pos.x * 70), (pos.y * 70));
	if (game->map->map[pos.y][pos.x] == COLLECT)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->collect, (pos.x * 70), (pos.y * 70));
	if (game->map->map[pos.y][pos.x] == EXIT)
		mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
			game->img->exit, (pos.x * 70), (pos.y * 70));
}

int	put_player(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->img->player, (game->player->x * 70), (game->player->y * 70));
	return (0);
}

t_graphics	*get_and_convert_images(t_so_long *game, t_graphics	*xpm)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	xpm = set_xpm(game);
	game->img->wall = XPM_IMG(game->mlx_connection, xpm->wall, &x, &y);
	if (game->img->wall == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->floor = XPM_IMG(game->mlx_connection, xpm->floor, &x, &y);
	if (game->img->floor == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->exit = XPM_IMG(game->mlx_connection, xpm->exit, &x, &y);
	if (game->img->exit == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->player = XPM_IMG(game->mlx_connection, xpm->player, &x, &y);
	if (game->img->player == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	game->img->collect = XPM_IMG(game->mlx_connection, xpm->collect, &x, &y);
	if (game->img->collect == NULL)
		clean_and_exit(XPM_CONVERSION_FAIL, game, xpm, NULL);
	return (free_graphic_struct(xpm), game->img);
}
