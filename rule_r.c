#include "rules.h"

/*
 * Shift up all elements of `stack` by 1.The first element becomes the last one.
 * */
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = t_stack_last(*stack);
	last->next = first;
}

void	ra(t_game *game)
{
	if (game == NULL)
		return ;
	rotate(&game->a);
	t_stack_push(&game->move, MOV_RA);
}

void	rb(t_game *game)
{
	if (game == NULL)
		return ;
	rotate(&game->b);
	t_stack_push(&game->move, MOV_RB);
}

void	rr(t_game *game)
{
	if (game == NULL)
		return ;
	ra(game);
	rb(game);
}
