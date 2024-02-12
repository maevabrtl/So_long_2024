#include "../../Includes/so_long.h"

int	var_is_a_fd(int index, va_list to_clean);
int	var_is_a_ptr(int index, va_list to_clean);
int	var_is_a_str(int index, char *format, va_list to_clean);
int	var_is_a_str_tab(int index, va_list to_clean);

int	var_is_a_str_tab(int index, va_list to_clean)
{
	char	**str_tab;

	str_tab = va_arg(to_clean, char **);
	if (str_tab != NULL)
	{
		while (*str_tab != NULL)
		{
			free(*str_tab);
			*str_tab = NULL;
			(*str_tab)++;
		}
		free(*str_tab);
		*str_tab = NULL;
		free(str_tab);
		str_tab = NULL;
	}
	return (index + 1);
}

int	var_is_a_str(int index, char *format, va_list to_clean)
{
	char	*str;

	index++;
	if (format[index] && format[index] == '2')
		return (var_is_a_str_tab(index, to_clean));
	str = va_arg(to_clean, char *);
	if (str != NULL)
		free(str);
	str = NULL;
	return (index);
}

int	var_is_a_ptr(int index, va_list to_clean)
{
	void	*ptr;

	ptr = va_arg(to_clean, void *);
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
	return (index + 1);
}

int	var_is_a_fd(int index, va_list to_clean)
{
	int	fd;

	fd = va_arg(to_clean, int);
	if (fd > 0) // fd >= 0 ?
		close(fd);
	return (index + 1);
}
