/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:42 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 08:44:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*t_list_new(int num);
t_list				*t_list_push(t_list **head, int num);
t_list				*t_list_remove(t_list **head, t_list *item);

void				t_list_clear(t_list **list);
void				t_list_add_before(t_list **elem, t_list *new_item);
void				t_list_add_after(t_list **elem, t_list *new_item);

int					t_list_exist(t_list *head, int num);

#endif
