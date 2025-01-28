/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:22:27 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 21:24:14 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H

# include "rules.h"
# include <stdbool.h>

typedef void	(*t_func)(t_game *);

typedef struct s_cost
{
	long		index;
	long		value;
}				t_cost;

long			t_stack_max(t_stack *head);
long			t_stack_min(t_stack *head);
long			t_stack_idx(t_stack *head, int num);
long			t_stack_size(t_stack *head);
long			t_stack_num_at(t_stack *head, long idx);

long			t_stack_next_idx(t_stack *stack, int num);
long			t_stack_prev_idx(t_stack *stack, int num);

void			t_action_repete(t_game *game, t_func func, int n);
void			t_action_rot_smart(t_game *game, long pos[2], int mode);
void			t_action_rot_top(t_game *game, long idx);

long			t_calc_cost(long *idxs, long a_size, long b_size);
long			t_calc_mode(long *idxs, long a_size, long b_size);
long			t_calc_best_b(t_game *game, long num, long len, bool is_idx);
long			t_calc_best_a(t_game *game, long a_size);

void			t_game_solve(t_game *game);

#endif
