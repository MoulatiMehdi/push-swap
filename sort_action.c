/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:23:38 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 21:24:06 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static long	min(long a, long b)
{
	if (a > b)
		return (b);
	return (a);
}

void	t_action_repete(t_game *game, t_func func, int n)
{
	if (func)
	{
		while (n-- > 0)
		{
			func(game);
		}
	}
}

void	t_action_rot_smart(t_game *game, long pos[2], int mode)
{
	if (mode == 0)
	{
		t_action_repete(game, rr, min(pos[0], pos[1]));
		t_action_repete(game, ra, pos[0] - min(pos[0], pos[1]));
		t_action_repete(game, rb, pos[1] - min(pos[0], pos[1]));
	}
	else if (mode == 1)
	{
		pos[0] = t_stack_size(game->a) - pos[0];
		if (pos[1] != 0)
			pos[1] = t_stack_size(game->b) - pos[1];
		t_action_repete(game, rrr, min(pos[0], pos[1]));
		t_action_repete(game, rra, pos[0] - min(pos[0], pos[1]));
		t_action_repete(game, rrb, pos[1] - min(pos[0], pos[1]));
	}
	else if (mode == 2)
	{
		t_action_repete(game, ra, pos[0]);
		t_action_repete(game, rrb, t_stack_size(game->b) - pos[1]);
	}
	else if (mode == 3)
	{
		t_action_repete(game, rra, t_stack_size(game->a) - pos[0]);
		t_action_repete(game, rb, pos[1]);
	}
}

/*
 *  Make the number with index `idx` at the top of the stack `a`
 *
 * */
void	t_action_rot_top(t_game *game, long idx)
{
	long	len;

	len = t_stack_size(game->a);
	if (idx <= len / 2)
	{
		while (idx-- > 0)
			ra(game);
	}
	else
	{
		while (idx++ < len)
			rra(game);
	}
}
