/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:35 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 21:20:02 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate_rev(t_list **a)
{
	t_list	*first;

	if (a == NULL || *a == NULL)
		return ;
	*a = (*a)->next;
}

void	rra(t_stack *stack)
{
	if (stack == NULL || stack->a == NULL)
		return ;
	rotate_rev(&stack->a);
}

void	rrb(t_stack *stack)
{
	if (stack == NULL || stack->b == NULL)
		return ;
	rotate_rev(&stack->b);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
