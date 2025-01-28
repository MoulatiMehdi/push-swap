/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:53:55 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 22:54:02 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

long	t_stack_size(t_stack *head)
{
	long	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

long	t_stack_num_at(t_stack *head, long idx)
{
	long	i;

	i = 0;
	while (i < idx)
	{
		head = head->next;
		i++;
	}
	return (head->num);
}

long	t_stack_max(t_stack *head)
{
	int		target;
	long	i;
	t_stack	*tmp;

	tmp = head;
	i = -1;
	target = tmp->num;
	while (tmp)
	{
		if (tmp->num > target)
			target = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (target);
}

long	t_stack_min(t_stack *head)
{
	int		target;
	long	i;
	t_stack	*tmp;

	tmp = head;
	i = -1;
	target = tmp->num;
	while (tmp)
	{
		if (tmp->num < target)
			target = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (target);
}
