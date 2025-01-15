/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:14:24 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/15 20:35:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
 *   WARN : be careful when using them (infinite loop might happend)
 *
 * */

void	t_list_add_after(t_list **elem, t_list *new_item)
{
	t_list	*curr;

	if (new_item == NULL || elem == NULL)
		return ;
	curr = *elem;
	if (curr == NULL)
	{
		*elem = new_item;
		new_item->next = new_item;
		new_item->prev = new_item;
		return ;
	}
	new_item->next = curr->next;
	new_item->prev = curr;
	curr->next->prev = new_item;
	curr->next = new_item;
}

void	t_list_add_before(t_list **elem, t_list *new_item)
{
	t_list	*curr;

	if (new_item == NULL || elem == NULL)
		return ;
	curr = *elem;
	if (curr == NULL)
	{
		*elem = new_item;
		new_item->next = new_item;
		new_item->prev = new_item;
		return ;
	}
	new_item->next = curr;
	new_item->prev = curr->prev;
	curr->prev->next = new_item;
	curr->prev = new_item;
}
