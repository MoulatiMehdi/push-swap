#include "sort.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc < 2)
		return (0);
	game = t_game_new(argc, argv);
	t_game_solve(game);
	t_game_clear(&game);
	return (EXIT_SUCCESS);
}
