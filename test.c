#include "rules.h"

int main()
{
    t_stack * head ;

    head = NULL;

    t_stack_push(&head, 6);
    t_stack_push(&head, 5);
    t_stack_push(&head, 4);

    t_stack_print(head);
    t_stack_clear(&head);
}
