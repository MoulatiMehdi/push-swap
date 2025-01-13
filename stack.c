#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

t_stack * t_stack_new(int number)
{
    t_stack* new_elem = malloc(sizeof(t_stack));

    if(new_elem == NULL)
        return NULL;
    new_elem->num = number;
    new_elem->next = NULL;

    return new_elem;

}

t_stack * t_stack_last(t_stack * head)
{
    if(head == NULL)
        return NULL;
    while(head->next !=NULL)
    {
        head = head->next;
    }
    return head;
}

t_stack * t_stack_push(t_stack **head,int number)
{
    t_stack * p;
    t_stack * new_elem;

    if(head == NULL)
        return NULL ;
    new_elem = t_stack_new(number);
    if(new_elem == NULL)
        return NULL;
    p = t_stack_last(*head);
    if(p == NULL)
        *head = new_elem;
    else
        p->next = new_elem;
    return new_elem;
}


t_stack * t_stack_pop(t_stack ** head)
{
    t_stack * prev_p;
    t_stack * p;

    if(head == NULL || *head == NULL)
        return NULL;
    prev_p = NULL;    
    p = *head;
    while(p-> next != NULL)
    {
        prev_p = p;
        p = p-> next;
    }
    if(prev_p == NULL)
        *head = NULL;
    else
        prev_p->next = NULL;
    return p;
}

void t_stack_print(t_stack * head)
{
    while(head != NULL)
    {
        printf("%2d -> ",head -> num);
        head = head->next;
    }
    printf("(NULL)\n");
}

void t_stack_clear(t_stack ** head)
{
    t_stack * p;

    if(head == NULL || *head == NULL)
        return ;
    p = *head;
    while(p != NULL)
    {
        *head = p->next;
        p->next = NULL;
        p->num = 0;
        free(p);
        p = *head;
    }
}

