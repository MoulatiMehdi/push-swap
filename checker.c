/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:28:17 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 22:51:48 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rules.h"
#include <stdlib.h>

void	ko(void)
{
	write(1, "KO\n", 3);
}

void	ok(void)
{
	write(1, "OK\n", 3);
}

void	error(void)
{
	write(2, "Error\n", 6);
}

int	action(t_game *game, char *move)
{
	if (ft_strcmp(move, "pa\n") == 0)
		return (pa(game), 1);
	if (ft_strcmp(move, "pb\n") == 0)
		return (pb(game), 1);
	if (ft_strcmp(move, "sa\n") == 0)
		return (sa(game), 1);
	if (ft_strcmp(move, "sb\n") == 0)
		return (sb(game), 1);
	if (ft_strcmp(move, "ss\n") == 0)
		return (ss(game), 1);
	if (ft_strcmp(move, "ra\n") == 0)
		return (ra(game), 1);
	if (ft_strcmp(move, "rb\n") == 0)
		return (rb(game), 1);
	if (ft_strcmp(move, "rr\n") == 0)
		return (rr(game), 1);
	if (ft_strcmp(move, "rra\n") == 0)
		return (rra(game), 1);
	if (ft_strcmp(move, "rrb\n") == 0)
		return (rrb(game), 1);
	if (ft_strcmp(move, "rrr\n") == 0)
		return (rrr(game), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	char	*move;

	if (argc < 2)
		return (0);
	game = t_game_new(argc, argv);
	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		if (action(game, move) == 0)
		{
			error();
			free(move);
			t_game_clear(&game);
			exit(1);
		}
	}
	if (t_game_is_sorted(game))
		ok();
	else
		ko();
	return (EXIT_SUCCESS);
}
