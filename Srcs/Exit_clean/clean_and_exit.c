/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabertha <mabertha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:40:53 by mabertha          #+#    #+#             */
/*   Updated: 2024/02/15 22:59:30 by mabertha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	exit_game(char *message, t_so_long *game)
{
	clean_and_exit(message, game, NULL, NULL);
	return (0);
}

int	exit_on_window_closing(t_so_long *game)
{
	clean_and_exit(WINDOW_CLOSED, game, NULL, NULL);
	return (0);
}

int	clean_and_exit(char *message, t_so_long *game, t_graphics *img, t_map *map)
{
	int	output_fd;

	output_fd = 2;
	if (*message == '\n')
		output_fd = 1;
	free_map_struct(map);
	free_graphic_struct(img);
	free_sl_struct(game);
	if (output_fd == 2)
		ft_putstr_fd("Error.\n> ", output_fd);
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
		if (to_free->player != NULL)
		{
			free(to_free->player);
			to_free->player = NULL;
		}
		free_mlx_var(to_free->mlx_connection, to_free->mlx_window,
			to_free->mlx_clean);
		free_map_struct(to_free->map);
		free(to_free);
		to_free = NULL;
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
