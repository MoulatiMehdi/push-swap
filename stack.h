/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:36:19 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 14:58:49 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	unsigned int	rank;
	struct s_stack	*next;
}					t_stack;

void				t_stack_clear(t_stack **head);

t_stack				*t_stack_push(t_stack **stack, int number);
t_stack				*t_stack_last(t_stack *head);
t_stack				*t_stack_pop(t_stack **head);

long	t_stack_size(t_stack *head);
long	t_stack_max(t_stack *head);
long	t_stack_min(t_stack *head);

long	t_stack_idx(t_stack *head, int num);
long	t_stack_next_idx(t_stack *stack, int num);
long	t_stack_prev_idx(t_stack *stack, int num);

#endif
