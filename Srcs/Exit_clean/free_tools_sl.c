/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools_sl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:40:59 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 23:01:09 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

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
	if (connection != NULL && display_or_both == 1)
	{
		mlx_destroy_display(connection);
		free(connection);
		connection = NULL;
		return ;
	}
	else if (connection != NULL && window != NULL && display_or_both == 2)
	{
		mlx_destroy_window(connection, window);
		mlx_destroy_display(connection);
		free(connection);
		connection = NULL;
	}
}

void	free_map_struct(t_map *map)
{
	if (map != NULL)
	{
		if (map->spawn != NULL)
		{
			free(map->spawn);
			map->spawn = NULL;
		}
		if (map->exit != NULL)
		{
			free(map->exit);
			map->exit = NULL;
		}
		free_str_var(map->map, map->height);
		free(map);
		map = NULL;
	}
}

void	free_str_var(char **to_free, int nb_to_free)
{
	int		i;

	i = 0;
	if (to_free != NULL)
	{
		while (i < nb_to_free)
		{
			free(to_free[i]);
			to_free[i] = NULL;
			i++;
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
