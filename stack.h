/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:38:48 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 08:37:43 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include "list.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack;

t_list		*t_stack_push(t_stack **stack, int num);
t_stack		*t_stack_new(void);
void		t_stack_clear(t_stack **stack);

#endif
