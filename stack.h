#ifndef STACK_H

#define STACK_H
#define NULL ((void *) 0 )

typedef struct s_stack 
{
    int num;
    struct s_stack *next;
} t_stack;


int t_stack_exist(t_stack * head,int num);

void t_stack_clear(t_stack ** head);
void t_stack_print(t_stack * head);

t_stack * t_stack_push(t_stack ** stack,int number);
t_stack * t_stack_last(t_stack * head);
t_stack * t_stack_pop(t_stack ** head);

#endif
