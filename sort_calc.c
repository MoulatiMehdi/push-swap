#include "sort.h"

static long	max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
 * Get the Leastest number of moves when combinate
 * two rotation types of (ra rra rb rrb )
 *  WARN : 5 parameters
 * */
long	t_calc_cost(long *idxs, long a_size, long b_size)
{
	int		i;
	long	tmp;
	long	move[4];
	t_cost	best;

	tmp = idxs[1];
	if (idxs[1] == 0)
		idxs[1] = idxs[0];
	move[1] = max(a_size - idxs[0], b_size - idxs[1]);
	move[2] = idxs[0] + b_size - idxs[1];
	move[3] = a_size - idxs[0] + idxs[1];
	i = 1;
	best.index = 0;
	best.value = max(idxs[0], idxs[1]);
	idxs[1] = tmp;
	while (i < 4)
	{
		if (move[i] < best.value)
		{
			best.index = i;
			best.value = move[i];
		}
		i++;
	}
	return (best.value);
}

long	t_calc_mode(long *idxs, long a_size, long b_size)
{
	int		i;
	long	tmp;
	long	move[4];
	t_cost	best;

	tmp = idxs[1];
	if (idxs[1] == 0)
		idxs[1] = idxs[0];
	move[1] = max(a_size - idxs[0], b_size - idxs[1]);
	move[2] = idxs[0] + b_size - idxs[1];
	move[3] = a_size - idxs[0] + idxs[1];
	i = 1;
	best.index = 0;
	best.value = max(idxs[0], idxs[1]);
	idxs[1] = tmp;
	while (i < 4)
	{
		if (move[i] < best.value)
		{
			best.index = i;
			best.value = move[i];
		}
		i++;
	}
	return (best.index);
}

/*
 *  Return index/cost of stack `b` item to push a `num` above it
 *
 * */
long	t_calc_best_b(t_game *game, long num, long len, bool is_idx)
{
	long	nmoves;
	long	pos[2];
	long	b_max;
	long	b_min;

	b_min = t_stack_min(game->b);
	b_max = t_stack_max(game->b);
	pos[0] = t_stack_idx(game->a, num);
	if (num < b_min || num > b_max)
		pos[1] = t_stack_idx(game->b, b_max);
	else
		pos[1] = t_stack_prev_idx(game->b, num);
	if (is_idx == true)
		nmoves = pos[1];
	else
		nmoves = t_calc_cost(pos, len, t_stack_size(game->b)) + 1;
	return (nmoves);
}

/*
 * Return index/cost of the element in stack `a` that, when moved to stack b,
	would result in the minimum cost according
 *
 * */
long	t_calc_best_a(t_game *game, long a_size)
{
	t_cost	best_cost;
	t_cost	curr_cost;
	t_stack	*curr;

	if (game->a == NULL)
		return (0);
	best_cost.value = t_calc_best_b(game, game->a->num, a_size, false);
	best_cost.index = 0;
	curr = game->a->next;
	curr_cost.index = 1;
	while (curr)
	{
		curr_cost.value = t_calc_best_b(game, curr->num, a_size, false);
		if (curr_cost.value < best_cost.value)
		{
			best_cost.value = curr_cost.value;
			best_cost.index = curr_cost.index;
		}
		curr = curr->next;
		curr_cost.index++;
	}
	return (best_cost.index);
}
