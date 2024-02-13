#include "../../Includes/so_long.h"

int		clean_and_exit(char *message, char *vars_to_free_list, t_so_long *struct_var, ...);
int		free_str_var(va_list to_clean, char alloc_ptr, int index);
void	free_images(t_so_long *game);
int		free_mlx_var(t_mlx to_clean, char display_or_both, int index);
void	free_struct(t_so_long *to_free);

int	clean_and_exit(char *message, char *vars_to_free_list, t_so_long *struct_var, ...)
{
	va_list	to_clean;
	int		index;

	index = -1;
	va_start(to_clean, vars_to_free_list);
	while (vars_to_free_list && vars_to_free_list[++index])
	{
		if (vars_to_free_list[index] == 'I')
			free_images(game);
		if (vars_to_free_list[index] == 'M')
			index = free_mlx_var(struct_var->mlx, vars_to_free_list[index + 1], index);
		if (vars_to_free_list[index] == 'S')
			free_struct(struct_var);
		if (vars_to_free_list[index] == 'C')
			index = free_str_var(va_arg(to_clean, char **), vars_to_free_list[index + 1], index);
		if (vars_to_free_list[index] == 'F')
			close(va_arg(to_clean, int));
	}
	va_end(to_clean);
	if (struct_var->win_or_not == FALSE)
		return (ft_putstr_fd(message, 2), exit(EXIT_FAILURE));
	return (ft_putstr_fd(message, 1), exit(EXIT_SUCCESS));
}

int	free_str_var(va_list to_clean, char alloc_ptr, int index)
{
	int		i;
	char	**to_free;

	i = 0;
	to_free = va_arg(to_clean, char **);
	if (to_free != NULL)
	{
		while (to_free[i] != NULL)
		{
			free(to_free[i]);
			to_free[i] = NULL;
			i++;
		}
		free(to_free[i]);
		to_free[i] = NULL;
		if (alloc_ptr == '2')
		{
			free(to_free);
			to_free = NULL;
		}
	}
	return (index + 1);
}

void	free_images(t_so_long *game)
{
	if (game->imgs.wall != NULL)
		mlx_destroy_image(game->mlx.connection, game->imgs.wall);
	if (game->imgs.floor != NULL)
		mlx_destroy_image(game->mlx.connection, game->imgs.floor);
	if (game->imgs.collectible != NULL)
		mlx_destroy_image(game->mlx.connection, game->imgs.collectible);
	if (game->imgs.exit != NULL)
		mlx_destroy_image(game->mlx.connection, game->imgs.exit);
	if (game->imgs.player != NULL)
		mlx_destroy_image(game->mlx.connection, game->imgs.player);
}

int	free_mlx_var(t_mlx to_clean, char display_or_both, int index)
{
	if (display_or_both == '1')
	{
		mlx_destroy_display(to_clean.connection);
		free(to_clean.connection);
		to_clean.connection = NULL;
	}
	else
		mlx_destroy_window(to_clean.connection, to_clean.window);
	return (index + 1);
}

void	free_struct(t_so_long *to_free)
{
	if (to_free != NULL)
	{
		free(to_free);
		to_free = NULL;
	}
}
