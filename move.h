#ifndef MOVE_H

# define MOVE_H

# include "stack.h"
# include <unistd.h>

typedef enum e_move
{
	MOV_PA = 0,
	MOV_PB = 1,
	MOV_SA,
	MOV_SB,
	MOV_SS,
	MOV_RA,
	MOV_RB,
	MOV_RR,
	MOV_RRA,
	MOV_RRB,
	MOV_RRR
}		t_move;

void	t_move_optimize(t_stack *head);
#endif
