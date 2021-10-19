/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:20:38 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/03 19:23:16 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	mark_before(t_list *lst, int idx)
{
	while (lst->head != 1)
	{
		if (lst->index > idx)
		{
			lst->tag = 1;
			idx = lst->index;
		}
		lst = lst->next;
	}
}

static void	mark_after(t_list *lst, t_list *head)
{
	t_list	*start;
	int		idx;

	start = head;
	idx = head->index;
	while (start)
	{
		if (start->index > idx)
		{
			start->tag = 1;
			idx = start->index;
		}
		start = start->next;
	}
	mark_before(lst, idx);
}

void	markup(t_list *lst)
{
	t_list	*start;

	start = lst;
	while (start->head != 1)
		start = start->next;
	start->tag = 1;
	mark_after(lst, start);
}

void	markup_clean(t_list *lst)
{
	while (lst)
	{
		lst->tag = 0;
		lst = lst->next;
	}
}
