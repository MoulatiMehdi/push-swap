/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:35 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 20:58:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	push(t_list **a, t_list **b)
{
	t_list	*first;

	if (a == NULL || b == NULL || *b == NULL)
		return ;
	first = t_list_remove(b, *b);
	t_list_add_before(a, first);
	*a = first;
}

void	pa(t_stack *stack)
{
	if (stack == NULL || stack->a == NULL)
		return ;
	push(&stack->a, &stack->b);
}

void	pb(t_stack *stack)
{
	if (stack == NULL || stack->b == NULL)
		return ;
	push(&stack->b, &stack->a);
}
