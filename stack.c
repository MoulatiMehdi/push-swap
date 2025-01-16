/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:48:25 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 08:41:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "stack.h"

t_stack	*t_stack_new(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

t_list	*t_stack_push(t_stack **stack, int num)
{
	if (stack == NULL || *stack == NULL)
		return (NULL);
	return (t_list_push(&(*stack)->a, num));
}

void	t_stack_clear(t_stack **stack)
{
	t_list_clear(&(*stack)->a);
	t_list_clear(&(*stack)->b);
	free(*stack);
	*stack = NULL;
}
