#include "rules.h"
#include <stdlib.h>


void t_game_clear(t_game ** game)
{
    if(game == NULL)
        return ;
    if(*game != NULL)
    {
        t_stack_clear(&(*game)->a);
        t_stack_clear(&(*game)->b);
    }
    free(*game);
    *game = NULL;
}

t_game * t_game_new(int * nbrs,unsigned long size)
{
    t_game * game;
    unsigned long i;

    game = malloc(sizeof(t_game));
    if(game == NULL)
        return NULL;
    i = 0; 
    game->a = NULL;
    game->b = NULL;

    while(i < size)
    {
        if(t_stack_push(&game->a, nbrs[i]) == NULL)
        {
            t_game_clear(&game);
            return NULL;
        }
        i++;
    }
    return game;
}


