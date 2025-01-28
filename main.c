/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:23:12 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 21:23:53 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
