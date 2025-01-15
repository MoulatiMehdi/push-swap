/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:35 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 20:57:52 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_list **a)
{
	t_list	*first;

	if (a == NULL || *a == NULL)
		return ;
	*a = (*a)->prev;
}

void	ra(t_stack *stack)
{
	if (stack == NULL || stack->a == NULL)
		return ;
	rotate(&stack->a);
}

void	rb(t_stack *stack)
{
	if (stack == NULL || stack->b == NULL)
		return ;
	rotate(&stack->b);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
