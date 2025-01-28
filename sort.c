/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:23:40 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 21:24:07 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	t_game_sort_three(t_game *game)
{
	int	test[3];

	if (game == NULL || game->size < 2)
		return ;
	if (game->size == 2)
	{
		if (game->a->num > game->a->next->num)
			sa(game);
		return ;
	}
	test[0] = game->a->num > game->a->next->num;
	test[1] = game->a->next->num > game->a->next->next->num;
	test[2] = game->a->next->next->num > game->a->num;
	if (test[0] + test[1] + test[2] == 2)
		sa(game);
	if (game->a->num > game->a->next->num)
		ra(game);
	if (game->a->next->num > game->a->next->next->num)
		rra(game);
}

/*
 * Find the index of the number inside `stack` that follow `num`
 *
 * */
void	t_game_sort(t_game *game)
{
	int		mode;
	long	pos[2];
	long	sizes[2];

	sizes[1] = t_stack_size(game->b);
	sizes[0] = t_stack_size(game->a);
	while (sizes[0] > 3)
	{
		pos[0] = t_calc_best_a(game, sizes[0]);
		pos[1] = t_calc_best_b(game, t_stack_num_at(game->a, pos[0]), sizes[0],
				true);
		mode = t_calc_mode(pos, sizes[0], sizes[1]);
		t_action_rot_smart(game, pos, mode);
		pb(game);
		sizes[0]--;
		sizes[1]++;
	}
	t_game_sort_three(game);
	while (game->b)
	{
		t_action_rot_top(game, t_stack_next_idx(game->a, game->b->num));
		pa(game);
	}
	t_action_rot_top(game, t_stack_idx(game->a, t_stack_min(game->a)));
}

void	t_game_solve(t_game *game)
{
	if (t_game_is_sorted(game))
		return ;
	if (game->size <= 3)
		t_game_sort_three(game);
	else
	{
		t_action_repete(game, pb, 1 + (game->size > 4));
		t_game_sort(game);
	}
	t_move_optimize(game->move);
}
