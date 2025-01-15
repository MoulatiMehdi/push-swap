/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:35 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 20:57:30 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap(t_list **stack)
{
	t_list	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == *stack)
		return ;
	second = (*stack)->next;
	t_list_remove(stack, second);
	t_list_add_before(stack, second);
}

void	sa(t_stack *stack)
{
	if (stack == NULL || stack->a == NULL)
		return ;
	swap(&stack->a);
}

void	sb(t_stack *stack)
{
	if (stack == NULL || stack->b == NULL)
		return ;
	swap(&stack->b);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
