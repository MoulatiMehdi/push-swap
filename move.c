/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:53:45 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/28 22:53:46 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

static void	t_move_print(int num)
{
	if (num == MOV_PA)
		write(1, "pa\n", 3);
	if (num == MOV_PB)
		write(1, "pb\n", 3);
	if (num == MOV_SA)
		write(1, "sa\n", 3);
	if (num == MOV_SB)
		write(1, "sb\n", 3);
	if (num == MOV_SS)
		write(1, "ss\n", 3);
	if (num == MOV_RA)
		write(1, "ra\n", 3);
	if (num == MOV_RB)
		write(1, "rb\n", 3);
	if (num == MOV_RR)
		write(1, "rr\n", 3);
	if (num == MOV_RRA)
		write(1, "rra\n", 4);
	if (num == MOV_RRB)
		write(1, "rrb\n", 4);
	if (num == MOV_RRR)
		write(1, "rrr\n", 4);
}

static void	t_move_helper(t_move rr, t_move rrr, long n)
{
	while (n < 0)
	{
		n++;
		t_move_print(rrr);
	}
	while (n > 0)
	{
		n--;
		t_move_print(rr);
	}
}

static void	t_move_rot(int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		ra--;
		rb--;
		t_move_print(MOV_RR);
	}
	while (ra < 0 && rb < 0)
	{
		ra++;
		rb++;
		t_move_print(MOV_RRR);
	}
	t_move_helper(MOV_RA, MOV_RRA, ra);
	t_move_helper(MOV_RB, MOV_RRB, rb);
}

void	t_move_optimize(t_stack *head)
{
	int	ra;
	int	rb;

	if (head == NULL)
		return ;
	ra = 0;
	rb = 0;
	while (head)
	{
		ra += (head->num == MOV_RA || head->num == MOV_RR);
		rb += (head->num == MOV_RB || head->num == MOV_RR);
		ra -= (head->num == MOV_RRA || head->num == MOV_RRR);
		rb -= (head->num == MOV_RRB || head->num == MOV_RRR);
		if (head->num < 4)
		{
			t_move_rot(ra, rb);
			ra = 0;
			rb = 0;
			t_move_print(head->num);
		}
		head = head->next;
	}
	t_move_rot(ra, rb);
}
