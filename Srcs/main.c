#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2 || parse_map(av[1]) == NOT_VALID)
		exit_error();
	return (0);
}
// int	main()
// {
// 	//void	*mlx_ptr;


// 	//mlx_ptr = mlx_init();
// 	dprintf(2, "okayyy\n");
// 	// init mlx
// 	// get and format map
// 	// check if valid

// 	// launch game
// 	// free and exit properly
// 	return (0);
// }
