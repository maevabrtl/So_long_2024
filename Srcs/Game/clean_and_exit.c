#include "../../Includes/so_long.h"

int		clean_and_exit(char *message, t_so_long *game, t_graphics *img, t_map *map);
void	free_sl_struct(t_so_long *to_free);
void	free_map_struct(t_map *map);
void	free_graphic_struct(t_graphics *img);
void	free_position(t_position *to_free);

int	clean_and_exit(char *message, t_so_long *game, t_graphics *img, t_map *map)
{
	int	output_fd;

	output_fd = 2;
	if (game != NULL && game->win_or_not == TRUE)
		output_fd = 1;
	free_map_struct(map);
	free_graphic_struct(img);
	free_sl_struct(game);
	ft_putstr_fd(message, output_fd);
	if (output_fd == 1)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
	return (0);
}

void	free_sl_struct(t_so_long *to_free)
{
	if (to_free != NULL)
	{
		free_images(to_free->mlx_connection, to_free->img);
		free_position(to_free->player);
		free_mlx_var(to_free->mlx_connection, to_free->mlx_window, to_free->mlx_clean);
		free_map_struct(to_free->map);
		free(to_free);
		to_free = NULL;
	}
}

void	free_map_struct(t_map *map)
{
	if (map != NULL)
	{
		if (map->spawn)
		free_position(map->spawn);
		free_position(map->exit);
		free_str_var(map->map);
		free(map);
		map = NULL;
	}
}

void	free_graphic_struct(t_graphics *img)
{
	if (img != NULL)
	{
		if (img->wall != NULL)
			free(img->wall);
		if (img->floor != NULL)
			free(img->floor);
		if (img->collect != NULL)
			free(img->collect);
		if (img->exit != NULL)
			free(img->exit);
		if (img->player != NULL)
			free(img->player);
		img->wall = NULL;
		img->floor = NULL;
		img->collect = NULL;
		img->exit = NULL;
		img->player = NULL;
		free(img);
		img = NULL;
	}
}

void	free_position(t_position *to_free)
{
	if (to_free != NULL)
		free(to_free);
	to_free = NULL;
}