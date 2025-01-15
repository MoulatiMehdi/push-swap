/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:48:25 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 18:19:06 by mmoulati         ###   ########.fr       */
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

void	t_stack_clear(t_stack **stack)
{
	t_list_clear(&(*stack)->a);
	t_list_clear(&(*stack)->b);
	free(*stack);
	*stack = NULL;
}
