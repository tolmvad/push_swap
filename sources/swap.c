/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:21:09 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/06 18:49:02 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *lst)
{
	t_list	tmp;

	if (lst && lst->next)
	{
		tmp.value = (lst->next)->value;
		tmp.index = (lst->next)->index;
		tmp.head = (lst->next)->head;
		(lst->next)->value = lst->value;
		(lst->next)->index = lst->index;
		(lst->next)->head = lst->head;
		lst->value = tmp.value;
		lst->index = tmp.index;
		lst->head = tmp.head;
	}
}

void	swap_d(t_list *list_a, t_list *list_b)
{
	swap(list_a);
	swap(list_b);
}
