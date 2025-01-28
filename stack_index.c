/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:53:56 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 22:54:02 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

long	t_stack_idx(t_stack *head, int num)
{
	long	i;

	i = 0;
	while (head)
	{
		if (head->num == num)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}

long	t_stack_next_idx(t_stack *stack, int num)
{
	t_stack	*tmp;
	int		target;

	tmp = stack;
	target = tmp->num;
	if (num > t_stack_max(stack))
		return (t_stack_idx(stack, t_stack_min(stack)));
	while (tmp)
	{
		if (tmp->num > num && (tmp->num < target || target < num))
			target = tmp->num;
		tmp = tmp->next;
	}
	return (t_stack_idx(stack, target));
}

long	t_stack_prev_idx(t_stack *stack, int num)
{
	t_stack	*tmp;
	int		target;

	tmp = stack;
	target = tmp->num;
	while (tmp)
	{
		if (tmp->num < num && (tmp->num > target || target > num))
			target = tmp->num;
		tmp = tmp->next;
	}
	return (t_stack_idx(stack, target));
}
