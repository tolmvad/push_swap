/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:19:03 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/16 18:38:06 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	tag_done(t_list *lst)
{
	while (lst)
	{
		if (lst->tag == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	solve_a(t_list **list_a, t_list **list_b)
{
	int		chk;

	chk = tag_done(*list_a);
	while (chk)
	{
		if (need_sa(*list_a))
			write(1, "sa\n", 3);
		else if ((*list_a)->tag == 0)
		{
			pb(list_a, list_b, 1);
			if (need_rb(*list_b))
				rb(list_b, 1);
		}
		else
			ra(list_a, 1);
		chk = tag_done(*list_a);
	}
}
