#include "rules.h"

/*
 * Shift down all elements of `stack` by 1.The first element becomes the last one.
 * */
static void rotate_rev(t_stack **stack)
{
    t_stack * prev_last;
    t_stack * last;

    if(stack == NULL || *stack == NULL || (*stack)-> next == NULL )
        return ;
    prev_last = NULL;
    last =  *stack;
    while(last->next != NULL)
    {
        prev_last = last;
        last = last->next;
    }
    prev_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

/*
 * Shift down all elements of stack `a` by 1.
 * The last element becomes the first one.
 * */
void rra(t_game * game)
{
    if(game == NULL)
        return ;
    rotate_rev(&game->a);
}

/*
 * Shift down all elements of stack `b` by 1.
 * The last element becomes the first one.
 * */
void rrb(t_game * game)
{
    if(game == NULL)
        return ;
    rotate_rev(&game->b);
}

/*
 * Shift down all elements of both stack `a` and `b` by 1.
 * The last element becomes the first one.
 * */
void rrr(t_game * game)
{
    if(game == NULL)
        return ;
    rra(game);
    rrb(game);
}
