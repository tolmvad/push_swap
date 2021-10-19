/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:46:04 by bcaffere          #+#    #+#             */
/*   Updated: 2021/10/06 15:20:25 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_start(t_list *lst)
{
	int	pos;

	pos = 0;
	while (lst->index != 0)
	{
		pos++;
		lst = lst->next;
	}
	return (pos);
}

static void	do_align(t_list **lst, t_move mv)
{
	while (mv.ra-- > 0)
		ra(lst, 1);
	while (mv.rra-- > 0)
		rra(lst, 1);
}

void	align(t_list **lst)
{
	int		start;
	int		len;
	t_move	mv;

	init_mv(&mv);
	start = find_start(*lst);
	if (start)
	{
		len = ft_lstlen(*lst);
		if (len - start < start)
			mv.rra = len - start;
		else
			mv.ra = start;
		do_align(lst, mv);
	}
}
