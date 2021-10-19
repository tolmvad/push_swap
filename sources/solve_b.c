/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:19:01 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/15 22:28:29 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_move_a(t_list *list_a, t_list *list_b, t_move *mv)
{
	int	low_mv;

	low_mv = move_a(list_a, list_b);
	if (ft_lstlen(list_a) - low_mv < low_mv)
		mv->rra = ft_lstlen(list_a) - low_mv;
	else
		mv->ra = low_mv;
}

t_move	give_best(t_list *start, t_list *first, t_move tmp, t_move bmv)
{
	int	total_tmp;
	int	total_bmv;

	if (start->index == first->index)
		return (tmp);
	total_tmp = tmp.ra + tmp.rb + tmp.rra + tmp.rrb;
	total_bmv = bmv.ra + bmv.rb + bmv.rra + bmv.rrb;
	if ((total_bmv == total_tmp) && (tmp.ra + tmp.rra < bmv.ra + bmv.rra))
		return (tmp);
	if (total_tmp < total_bmv)
		return (tmp);
	return (bmv);
}

t_move	find_best_move(t_list *list_a, t_list *list_b)
{
	t_move	bmv;
	t_move	tmp;
	t_list	*start;
	int		low_mv;

	start = list_b;
	while (list_b)
	{
		init_mv(&tmp);
		find_move_a(list_a, list_b, &tmp);
		low_mv = move_b(start, list_b);
		if (ft_lstlen(start) - low_mv < low_mv)
			tmp.rrb = ft_lstlen(start) - low_mv;
		else
			tmp.rb = low_mv;
		bmv = give_best(start, list_b, tmp, bmv);
		list_b = list_b->next;
	}
	return (bmv);
}

void	solve_b(t_list **list_a, t_list **list_b)
{
	t_move	mv;

	while (*list_b)
	{
		mv = find_best_move(*list_a, *list_b);
		do_move(list_a, list_b, mv);
		pa(list_a, list_b, 1);
	}
}
