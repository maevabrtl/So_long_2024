#include "../../Includes/so_long.h"

void	map_error(int error_code);
void	nb_args_error(int error_code);
void	print_error(int error_code);

void	print_error(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_fd("\nCongrats, it works !\n\n", 1);
		ft_putstr_fd("\033[0;33mEND\n\033[0m", 2);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("Error\n> ", 2);
	if (error_code == 2)
		ft_putstr_fd(RULE_NEED_A_MAP, 2);
	if (error_code >= 3 && error_code <= 13)
		map_error(error_code);
	if (error_code == 14)
		ft_putstr_fd(ALLOC_ERROR, 2);
	if (error_code == 15)
		ft_putstr_fd(DIRTY_TALK, 2);
	if (error_code == 16)
		ft_putstr_fd(EMPTY_MAP, 2);
	ft_putstr_fd("\033[0;33mEND\n\033[0m", 2);
}

void	map_error(int error_code)
{
	if (error_code == 3)
		ft_putstr_fd(OPEN_FAILED, 2);
	if (error_code == 4)
		ft_putstr_fd(RULE_RECTANGLE, 2);
	if (error_code == 5)
		ft_putstr_fd(RULE_VALID_ELEM, 2);
	if (error_code == 6)
		ft_putstr_fd(RULE_PLAYER_1, 2);
	if (error_code == 7)
		ft_putstr_fd(RULE_PLAYER_2, 2);
	if (error_code == 8)
		ft_putstr_fd(RULE_COLL, 2);
	if (error_code == 9)
		ft_putstr_fd(RULE_EXIT_1, 2);
	if (error_code == 10)
		ft_putstr_fd(RULE_EXIT_2, 2);
	if (error_code == 11)
		ft_putstr_fd(RULE_CLOSED, 2);
	if (error_code == 12)
		ft_putstr_fd(RULE_WINNABLE, 2);
	if (error_code == 13)
		ft_putstr_fd(RULE_BER, 2);
}
