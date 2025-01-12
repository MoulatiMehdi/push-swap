#include "rules.h"

/*
 * Swap the first 2 elements at the top of the `stack` .
 * Do nothing if there is only one or no elements.
 * */
static void swap(t_stack ** stack)
{
    t_stack * first;
    t_stack * second;
    
    if(stack == NULL || *stack  == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    second = first->next;
    first->next = second -> next;
    second->next = first;
    *stack = second;
}

void sa(t_game *game)
{
    if(game == NULL)
        return ;
    swap(&game->a);
}

/*
 * Swap the first 2 elements at the top of stack `b`.
 * Do nothing if there is only one or no elements.
 * */
void sb(t_game *game)
{
    if(game == NULL)
        return ;
    swap(&game->b);
}
