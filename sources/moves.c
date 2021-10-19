/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:38:23 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/06 15:51:17 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_mv(t_move *mv)
{
	mv->ra = 0;
	mv->rb = 0;
	mv->rra = 0;
	mv->rrb = 0;
}

void	do_move(t_list **list_a, t_list **list_b, t_move mv)
{
	if (mv.ra && mv.rb)
		while (mv.ra && mv.rb)
			rr(list_a, list_b, &(mv.ra), &(mv.rb));
	else if (mv.rra && mv.rrb)
		while (mv.rra && mv.rrb)
			rrr(list_a, list_b, &(mv.rra), &(mv.rrb));
	while (mv.ra-- > 0)
		ra(list_a, 1);
	while ((mv.rb-- > 0))
		rb(list_b, 1);
	while (mv.rra-- > 0)
		rra(list_a, 1);
	while (mv.rrb-- > 0)
		rrb(list_b, 1);
}

static int	move_less(t_list *list_a)
{
	int	i;
	int	min;

	i = 0;
	min = idx_min(list_a);
	while (list_a->index != min)
	{
		i++;
		list_a = list_a->next;
	}
	return (i);
}

int	move_a(t_list *list_a, t_list *list_b)
{
	int	i;
	int	idx;

	i = 0;
	idx = list_b->index;
	if (idx < idx_min(list_a))
		return (move_less(list_a));
	if (idx > idx_last(list_a) && idx < list_a->index)
		return (0);
	while (list_a->next)
	{
		i++;
		if (list_a->index < idx && (list_a->next)->index > idx)
			return (i);
		list_a = list_a->next;
	}
	return (-1);
}

int	move_b(t_list *lst, t_list *elem)
{
	int	i;

	i = 0;
	while (lst->index != elem->index)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
