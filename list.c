/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:31:15 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 20:30:35 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

t_list	*t_list_new(int num)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->num = num;
	new_elem->next = new_elem;
	new_elem->prev = new_elem;
	return (new_elem);
}

t_list	*t_list_push(t_list **head, int num)
{
	t_list	*new_elem;

	if (head == NULL)
		return (NULL);
	new_elem = t_list_new(num);
	if (!new_elem)
		return (NULL);
	if (*head == NULL)
		return (*head = new_elem);
	new_elem->prev = (*head)->prev;
	new_elem->next = *head;
	(*head)->prev = new_elem;
	new_elem->prev->next = new_elem;
	return (new_elem);
}

t_list	*t_list_remove(t_list **head, t_list *item)
{
	if (head == NULL || *head == NULL || item == NULL)
		return (item);
	if (*head == item)
	{
		if ((*head)->next == item && (*head)->prev == item)
		{
			*head = NULL;
			return (item);
		}
		*head = item->next;
	}
	item->prev->next = item->next;
	item->next->prev = item->prev;
	item->next = item;
	item->prev = item;
	return (item);
}

void	t_list_clear(t_list **list)
{
	t_list	*start;
	t_list	*tmp;
	t_list	*p;

	if (list == NULL || *list == NULL)
		return ;
	start = *list;
	p = start;
	while (1)
	{
		tmp = p->next;
		p->next = NULL;
		p->prev = NULL;
		free(p);
		p = tmp;
		if (p == start)
			break ;
	}
	*list = NULL;
}
