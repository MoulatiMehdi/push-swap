/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:54:18 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 22:54:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
