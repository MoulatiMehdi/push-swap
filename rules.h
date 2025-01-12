#ifndef RULES_H

#define RULES_H
#include "../stack/stack.h"


typedef struct s_game
{
    t_stack* a;
    t_stack* b;
}t_game;

/*
 *  Create a new instance for `t_game` object and initialize the stack `a` with the numbers in `nbrs` array
 * */
t_game * t_game_new(int * nbrs,unsigned long size);

/*
 * Clean up the all the stack and sets the pointer `t_game *` object to `NULL`
 * */
void t_game_clear(t_game ** game);
/*
 * Swap the first 2 elements at the top of stack `a`.
 * Do nothing if there is only one or no elements.
 * */
void sa(t_game *game);

/*
 * Swap the first 2 elements at the top of stack `b`.
 * Do nothing if there is only one or no elements.
 * */
void sb(t_game *game);

/*
 * Take the first element at the top of `b` and put it at the top of `a`.
 * Do nothing if `b` is empty.
 * */
void pa(t_game *game);

/*
 * Take the first element at the top of `a` and put it at the top of `b`.
 * Do nothing if `a` is empty.
 * */
void pb(t_game *game);

/*
 * Shift up all elements of `a` by 1.The first element becomes the last one.
 * */
void ra(t_game * game);

/*
 * Shift up all elements of `b` by 1.The first element becomes the last one.
 * */
void rb(t_game * game);

/*
 * Shift up all elements of `a` and `b` by 1.The first element becomes the last one.
 * */
void rr(t_game * game);

/*
 * Shift down all elements of `a` by 1.The first element becomes the last one.
 * */
void rra(t_game * game);
/*
 * Shift down all elements  `b` by 1.The first element becomes the last one.
 * */
void rrb(t_game * game);

/*
 * Shift down all elements of `a` and `b` by 1.The first element becomes the last one.
 * */
void rrr(t_game * game);

#endif
