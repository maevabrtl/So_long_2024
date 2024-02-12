#include "../../Includes/so_long.h"

/*	< Variadic function "clean_and_exit" >
This function takes as parameters an int which defines
the error we'll have to print, another int for the amount
of variables to release with clean, a string "format" that
contains the format specifiers, for the variables to clean
which are given in the "..." after "format". To get those
args we'll use the va_arg function in a sub-function dep-
ending on the types provided by the string "format".
Function call example :
	clean_and_exit(4, 3, " %C2 %F %C", ...)*/
void	clean_and_exit(int	error_code, int	nb_to_clean, char *format, ...);
void	get_var_and_clean_it(int nb_to_clean, char *format, va_list to_clean);

void	clean_and_exit(int	error_code, int	nb_to_clean, char *format, ...)
{
	va_list	to_clean;

	if (nb_to_clean > 0)
	{
		va_start(to_clean, format);
		get_var_and_clean_it(nb_to_clean, format, to_clean);
		va_end(to_clean);
	}
	print_error(error_code);
	exit(EXIT_FAILURE);
}

void	get_var_and_clean_it(int nb_to_clean, char *format, va_list to_clean)
{
	int	index;

	index = 0;
	while (format[index] && nb_to_clean > 0)
	{
		if (format[index] && format[index] == '%')
		{
			index++;
			if (format[index] && format[index] == 'C')
				index = var_is_a_str(index + 1, format, to_clean);
			else if (format[index] && format[index] == 'V')
				index = var_is_a_ptr(index + 1, to_clean);
			else if (format[index] && format[index] == 'F')
				index = var_is_a_fd(index + 1, to_clean);
		}
		if (index == 0)
			break ;
		nb_to_clean--;
	}
}
