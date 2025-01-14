/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:42 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/14 17:52:33 by mmoulati         ###   ########.fr       */
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
t_list				*t_list_enqueue(t_list **head, int num);

void				t_list_clear(t_list **list);
#endif
