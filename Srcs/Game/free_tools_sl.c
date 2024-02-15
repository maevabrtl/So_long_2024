#include "../../Includes/so_long.h"

void	free_images(void *connection, t_graphics *img);
void	free_mlx_var(void *connection, void *window, int display_or_both);
void	free_str_var(char **to_free);
void	ft_free_sl(char *str, int fd);

void	free_images(void *connection, t_graphics *img)
{
	if (img != NULL)
	{
		if (img->wall != NULL)
			mlx_destroy_image(connection, img->wall);
		img->wall = NULL;
		if (img->floor != NULL)
			mlx_destroy_image(connection, img->floor);
		img->floor = NULL;
		if (img->collect != NULL)
			mlx_destroy_image(connection, img->collect);
		img->collect = NULL;
		if (img->exit != NULL)
			mlx_destroy_image(connection, img->exit);
		img->exit = NULL;
		if (img->player != NULL)
			mlx_destroy_image(connection, img->player);
		img->player = NULL;
		free(img);
		img = NULL;
	}
}

void	free_mlx_var(void *connection, void *window, int display_or_both)
{
	if (display_or_both == 1)
	{
		mlx_destroy_display(connection);
		free(connection);
		connection = NULL;
		return ;
	}
	else
	{
		mlx_destroy_window(connection, window);
		mlx_destroy_display(connection);
		free(connection);
		connection = NULL;
	}
}

void	free_str_var(char **to_free)
{
	int		i;

	i = 0;
	if (to_free != NULL)
	{
		if (to_free[i] != NULL)
		{
			while (to_free[i] != NULL)
			{
				free(to_free[i]);
				to_free[i] = NULL;
				i++;
			}
			if (to_free[i])
				free(to_free[i]);
			to_free[i] = NULL;
		}
		free(to_free);
		to_free = NULL;
	}
}

void	ft_free_sl(char *str, int fd)
{
	if (str && str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (fd > 2)
		close(fd);
}
