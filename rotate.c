#include "rules.h"

/*
 * Shift up all elements of `stack` by 1.The first element becomes the last one.
 * */
static void rotate(t_stack ** stack)
{
    t_stack * first;
    t_stack * last;

    if(stack == NULL || *stack == NULL || (*stack)-> next == NULL )
        return ;
    first = *stack;
    *stack = first->next;
    last = t_stack_last(*stack);
    last->next = first;
}


/*
 * Shift up all elements of `a` by 1.The first element becomes the last one.
 * */
void ra(t_game * game)
{
    if(game == NULL)
        return ;
    rotate(&game->a);
}


void rb(t_game * game)
{
    if(game == NULL)
        return ;
    rotate(&game->b);
}

void rr(t_game * game)
{
    if(game == NULL)
        return ;
    ra(game);
    rb(game);
}
