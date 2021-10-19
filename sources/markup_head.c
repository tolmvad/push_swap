/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:20:31 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/03 19:20:32 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_max(t_max *max, t_list *elem)
{
	max->len = 0;
	max->index = elem->index;
	max->current = elem->index;
}

static void	before_head(t_list *lst, t_max *max)
{
	while (lst->index != max->index)
	{
		if (max->current < lst->index)
		{
			max->current = lst->index;
			(max->len)++;
		}
		lst = lst->next;
	}
}

static t_max	after_head(t_list *lst, t_list *elem)
{
	t_list	*run;
	t_max	max;

	run = elem;
	init_max(&max, elem);
	while (run)
	{
		if (max.current < run->index)
		{
			max.current = run->index;
			(max.len)++;
		}
		run = run->next;
	}
	before_head(lst, &max);
	return (max);
}

static void	mark_head(t_list *lst, t_max *head)
{
	while (lst->index != head->index)
		lst = lst->next;
	lst->head = 1;
}

void	markup_head(t_list *lst)
{
	t_list	*start;
	t_max	head;
	t_max	local_max;

	start = lst;
	init_max(&head, lst);
	while (lst)
	{
		local_max = after_head(start, lst);
		if (local_max.len > head.len)
			head = local_max;
		if (local_max.len == head.len && local_max.index < head.index)
			head = local_max;
		lst = lst->next;
	}
	mark_head(start, &head);
	markup(start);
}
